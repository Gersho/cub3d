/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:40:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/04 16:55:04 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	bmp_header(t_vars *vars, int fd)
{
	int	filesize;
	int offset;
	// Header 	14 bytes 	  	Windows Structure: BITMAPFILEHEADER
	// Signature 	2 bytes 	0000h 	'BM'
	// FileSize 	4 bytes 	0002h 	File size in bytes
	// reserved 	4 bytes 	0006h 	unused (=0)
	// DataOffset 	4 bytes 	000Ah 	Offset from beginning of file to the beginning of the bitmap data
// file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + 4 + \
// 	(cfg->resolution.x * cfg->resolution.y * 4);
	offset = 54;
	filesize = offset + (vars->cubinfo->res[0] * vars->cubinfo->res[1] * 4);
	write(fd, "BM", 2);        //magic num
	write(fd, &filesize, 4);  //file size
	write(fd, "\0\0\0\0", 4);  //reserved
	write(fd, &offset, 4);  // data offset
}

static void bmp_infoheader(t_vars *vars, int fd)
{
	int i;
	/*
		InfoHeader 	40 bytes 	  	Windows Structure: BITMAPINFOHEADER
		Size 	4 bytes 	000Eh 	Size of InfoHeader =40 
		Width 	4 bytes 	0012h 	Horizontal width of bitmap in pixels
		Height 	4 bytes 	0016h 	Vertical height of bitmap in pixels
		Planes 	2 bytes 	001Ah 	Number of Planes (=1)
		Bits Per Pixel 	2 bytes 	001Ch 	Bits per Pixel used to store palette entry information. This also identifies in an indirect way the number of possible colors. Possible values are:
				1 = monochrome palette. NumColors = 1  
				4 = 4bit palletized. NumColors = 16  
				8 = 8bit palletized. NumColors = 256 
				16 = 16bit RGB. NumColors = 65536
				24 = 24bit RGB. NumColors = 16M
		Compression 	4 bytes 	001Eh 	Type of Compression  
				0 = BI_RGB   no compression  
				1 = BI_RLE8 8bit RLE encoding  
				2 = BI_RLE4 4bit RLE encoding
		ImageSize 	4 bytes 	0022h 	(compressed) Size of Image 
				It is valid to set this =0 if Compression = 0
		XpixelsPerM 	4 bytes 	0026h 	horizontal resolution: Pixels/meter
		YpixelsPerM 	4 bytes 	002Ah 	vertical resolution: Pixels/meter
		Colors Used 	4 bytes 	002Eh 	Number of actually used colors. For a 8-bit / pixel bitmap this will be 100h or 256.
		Important Colors 	4 bytes 	0032h 	Number of important colors 
		0 = all
*/
	
	write(fd, 40, 4);
	write(fd, &vars->cubinfo->res[0], 4);
	write(fd, &vars->cubinfo->res[1], 4);
	write(fd, 1, 2);
	write(fd, 24, 2);
	i = 0;
	while (i < 24)
	{
		write(fd, "\0", 1);
	}
	// write(fd, 0, 4); //compression
	// write(fd, 0, 4);
	//

}

static void bmp_pixeldata(t_vars *vars, int fd)
{
	
}

void	img_to_bmp(t_vars *vars)
{
	int		fd;
	char	*name;

	name = ft_strdup("image.bmp");
	if (!name)
	{
		//clamerd exit
	}
	fd = open(name, O_CREAT | O_RDWR, 0644);
	if (!fd)
	{
		//clamerd exit
	}
	bmp_header(vars, fd);
	bmp_infoheader(vars, fd);
	bmp_pixeldata(vars, fd);
	close(fd);
	free(name);
}
