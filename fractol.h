/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:27:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 11:54:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>

# define WIDTH 1286
# define HEIGHT 1000
# define THREADS 1000
# define ITERATION 50
# define X_ZOOM 50 * WIDTH / HEIGHT
# define Y_ZOOM 50
# define MOVE 40

# define OCRE 0xffaf70

# define GAP_X img->ax->gap_x
# define GAP_Y img->ax->gap_y
# define POW ft_power

typedef struct			s_axis
{
	float				xmax;
	float				xmin;
	float				ymax;
	float				ymin;
	float				xamp;
	float				yamp;
	float				gap_x;
	float				gap_y;
}						t_axis;

typedef struct			s_point
{
	int					p;
	double				x;
	double				y;
	int					mod;
	int					color;
}						t_point;

typedef struct			s_img
{
	char				*ttl;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					height;
	char				*str;
	int					bpp;
	int					s_l;
	int					endian;
	t_axis				*ax;
	int					(*fractal)(t_point *, struct s_img *);
	int					mouse_x0;
	int					mouse_y0;
	int					mouse_x1;
	int					mouse_y1;
	double				c_r;
	double				c_im;
	float				col;
	int					iter;
	int					mouse_track;
}						t_img;

typedef struct			s_segment
{
	t_img				*img;
	int					start;
	int					end;
	t_point				*p;
}						t_segment;

typedef struct			s_all
{
	t_segment			*seg[THREADS];
}						t_all;

int						ft_check_title(char *title);
char					*ft_error_message(void);
int						ft_fractal(t_img *img);
int						ft_create_threads(t_img *img);
t_all					*ft_all(void);
t_segment				*ft_threads_init(t_segment **seg);
t_img					*ft_ptr_init(char *title);
t_point					*ft_point_init(void);
t_axis					*ft_axis_init(char *title);
void					ft_clear_and_replace(t_img *ptr);
void					ft_mandel_axis(t_axis *ax);
void					ft_julia_axis(t_axis *ax);
void					ft_get_controls(t_img *ptr);
void					ft_print_menu(void *mlx_ptr, void *win_ptr);
void					ft_select_fractal(t_img *img);
void					ft_zoom(int key, t_img *ptr);
void					ft_move(int key, t_img *ptr);
void					ft_change_iteration(int key, t_img *ptr);
void					ft_enable_or_disable_mouse_move(int key, t_img *ptr);
void					ft_free_image(t_img *img);
int						ft_choose_color(int i);
int						ft_color(int i);
int						ft_mandel(t_point *p, t_img *img);
int						ft_mandel3(t_point *p, t_img *img);
int						ft_mandel4(t_point *p, t_img *img);
int						ft_mandel5(t_point *p, t_img *img);
int						ft_julia3(t_point *p, t_img *img);
int						ft_julia4(t_point *p, t_img *img);
int						ft_julia5(t_point *p, t_img *img);
int						ft_julia(t_point *p, t_img *img);
int						ft_burningship(t_point *p, t_img *img);
int						ft_tricorn(t_point *p, t_img *img);
int						ft_perpendicular_buffalo(t_point *p, t_img *img);
int						ft_perpendicular_celtic(t_point *p, t_img *img);
int						ft_celtic_mandelbar(t_point *p, t_img *img);
void					ft_term_thread(char *str, t_segment **segment, int i);

#endif
