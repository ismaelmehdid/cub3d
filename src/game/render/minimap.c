/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:59:42 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/12 22:05:50 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void draw_elem(t_cub_data *data, int i[2], int color,
                                                float offset_x_y[2])
{
	int x;
	int y;
	int end_x;
	int end_y;

	x = (i[1] - offset_x_y[0]) * data->utils.minimap.cell_width;
	y = (i[0] - offset_x_y[1]) * data->utils.minimap.cell_height;
	end_x = x + data->utils.minimap.cell_width;
	end_y = y + data->utils.minimap.cell_height;

	while (y < end_y)
	{
		x = (i[1] - offset_x_y[0]) * data->utils.minimap.cell_width;
		while (x < end_x)
		{
			if (x >= 0 && y >= 0)
				ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
	    y++;
	}
}

static void draw_map_elements(t_cub_data *dat, int i[2], float offset_x_y[2])
{
    dat->utils.minimap.cell_width = MINIMAP_SIZE / (2 * RANGE);
    dat->utils.minimap.cell_height = MINIMAP_SIZE / (2 * RANGE);
    offset_x_y[0] = dat->player_data.mm_x / dat->utils.minimap.cell_width - RANGE;
    offset_x_y[1] = dat->player_data.mm_y / dat->utils.minimap.cell_height - RANGE;
    i[0] = (int)offset_x_y[1];
    while (i[0] < (int)offset_x_y[1] + 2 * RANGE)
    {
        i[1] = (int)offset_x_y[0];
        while (i[1] < (int)offset_x_y[0] + 2 * RANGE)
        {
            if (i[0] >= 0 && i[0] < dat->utils.map_height && \
                i[1] >= 0 && i[1] < ft_strlen(dat->settings.map[i[0]]))
            {
                if (dat->settings.map[i[0]][i[1]] == '1')
                    draw_elem(dat, i, WHITE, offset_x_y);
                else if (dat->settings.map[i[0]][i[1]] == '0' || \
                    dat->settings.map[i[0]][i[1]] == dat->player_data.pole)
                    draw_elem(dat, i, GREY, offset_x_y);
            }
            i[1]++;
        }
        i[0]++;
    }
}

static void draw_player_on_minimap(t_cub_data *data, int x, int y)
{
    int start_x;
    int start_y;
    int end_x;
    int end_y;

    start_x = MINIMAP_SIZE / 2 - PLAYER_DOT_SIZE / 2;
    start_y = MINIMAP_SIZE / 2 - PLAYER_DOT_SIZE / 2;
    end_x = start_x + PLAYER_DOT_SIZE;
    end_y = start_y + PLAYER_DOT_SIZE;
    y = start_y;
    while (y < end_y)
    {
        x = start_x;
        while (x < end_x)
        {
            if (x >= 0 && y >= 0)
                ft_mlx_pixel_put(data, x, y, RED);
            x++;
        }
        y++;
    }
}

static void draw_view_direction(t_cub_data *data)
{
    int     start_x_y[2];
    int     end_x_y[2];
    int     line_length;
    float   angle_rad;

    line_length = 15;
    angle_rad = degToRad(data->player_data.angle);
    start_x_y[0] = MINIMAP_SIZE / 2;
    start_x_y[1] = MINIMAP_SIZE / 2;
    end_x_y[0] = start_x_y[0] + line_length * cos(angle_rad);
    end_x_y[1] = start_x_y[1] - line_length * sin(angle_rad);
    bresenham_line_draw(data, start_x_y, end_x_y);
}

void draw_minimap(t_cub_data *data)
{
	int		i[2];
	float	offset_x_y[2];

	i[0] = 0;
	i[1] = 0;
	offset_x_y[0] = 0;
	offset_x_y[1] = 0;
	data->player_data.mm_x = scale_player_pos(data->player_data.x);
	data->player_data.mm_y = scale_player_pos(data->player_data.y);
	draw_map_elements(data, i, offset_x_y);
	draw_player_on_minimap(data, data->player_data.mm_x, data->player_data.mm_y);
	draw_view_direction(data);
    minimap_frame(data);
}
