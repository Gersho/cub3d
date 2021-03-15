/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:59:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/15 14:03:54 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cubinfo_print(t_cubinfo *cubinfo)
{
	printf("res:%d,%d\n", cubinfo->res[0], cubinfo->res[1]);
	printf("color_floor:%d,", cubinfo->color_floor[0]);
	printf("%d,", cubinfo->color_floor[1]);
	printf("%d\n", cubinfo->color_floor[2]);
	printf("color_ceil:%d,", cubinfo->color_ceil[0]);
	printf("%d,", cubinfo->color_ceil[1]);
	printf("%d\n", cubinfo->color_ceil[2]);
	printf("map_size:%d,", cubinfo->map_size[0]);
	printf("%d\n", cubinfo->map_size[1]);
	printf("map_start:%d\n", cubinfo->map_start);
	printf("Path_N:%s\n", cubinfo->path_N);
	printf("Path_S:%s\n", cubinfo->path_S);
	printf("Path_E:%s\n", cubinfo->path_E);
	printf("Path_W:%s\n", cubinfo->path_W);
	printf("Path_sprite:%s\n", cubinfo->path_sprite);
	printf("sprite:%d,%d\n", cubinfo->sprite[0], cubinfo->sprite[1]);
	printf("spawn:%d,%d\n", cubinfo->spawn[0], cubinfo->spawn[1]);
	printf("facing:%c\n", cubinfo->facing);
	ft_print_char_2d(cubinfo->map);
}

void	coord_print(t_coord	coord)
{
	printf("coord.x:%f\n", coord.x);
	printf("coord.y:%f\n", coord.y);
	printf("coord.z:%f\n", coord.z);
}

void	color_print(t_trgb trgb)
{
	printf("trgb.t: %d\n", trgb.t);
	printf("trgb.r: %d\n", trgb.r);
	printf("trgb.g: %d\n", trgb.g);
	printf("trgb.b: %d\n", trgb.b);
}

void reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
} 
  
// Converts a given integer x to string str[].  
// d is the number of digits required in the output.  
// If d is more than the number of digits in x,  
// then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
  
    // If number of digits required is more, then 
    // add 0s at the beginning 
    while (i < d) 
        str[i++] = '0'; 
  
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 
  
// Converts a floating-point/double number to a string. 
void ftoa(float n, char* res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart = (int)n; 
  
    // Extract floating part 
    float fpart = n - (float)ipart; 
  
    // convert integer part to string 
    int i = intToStr(ipart, res, 0); 
  
    // check for display option after point 
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 
  
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter  
        // is needed to handle cases like 233.007 
        fpart = fpart * pow(10, afterpoint); 
  
        intToStr((int)fpart, res + i + 1, afterpoint); 
    } 
} 