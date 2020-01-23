/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:28:02 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 16:24:53 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include "libft.h"
# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# define WIN_HEIGHT     1000
# define WIN_WIDTH		1500
# define MAP_WIDTH		1000
# define EPSILON    	(1.0E-8)
# define INTERSECT_TOL	1
# define YELLOW         0x00FFFF00
# define GREY           0x00383434
# define RED            0x00FF0000
# define BLUE           0x000000FF
# define PURPLE         0x00FF00FF
# define WHITE          0x00FFFFFF
# define DARK_BLUE      0x005555FF
# define GREEN          0x0000FF00
# define AMASK          0xFF000000
# define RMASK          0x00FF0000
# define GMASK          0x0000FF00
# define BMASK          0x000000FF
# define STEP_MOVE		50
# define STEP_GRID		32
# define NUM_TEXTURES		64
# define NUM_AUDIO			5
# define NUM_WALL_TEXTURES	6
# define NUM_FLAG_TEXTURES	1
# define NUM_MONSTER		2
# define NUM_TTF			2

typedef enum				e_bool
{
	true, false
}							t_bool;

typedef	enum				e_option
{
	draw, wall_select, sector_select, player, monster_mode,
	flag_mode, objet_mode
}							t_option;

typedef struct				s_monster
{
	unsigned		texture;
	int				sector_idx;
	float			start[3];
	float			end[3];
	float			ceil;
	float			floor;
	float			origin[3];
	float			lookat[3];
}							t_monster;

typedef struct				s_monster_lst
{
	t_monster				*monster;
	struct s_monster_lst	*next;
}							t_monster_lst;

typedef struct				s_pickup
{
	unsigned			texture;
	int					item_id;
	int					sector_idx;
	float				start[3];
	float				end[3];
	float				ceil;
	float				floor;
	float				center[3];
	float				lookat[3];
}							t_pickup;

typedef struct				s_pickup_lst
{
	t_pickup			*pickup;
	struct s_pickup_lst	*next;
}							t_pickup_lst;

typedef struct				s_flag
{
	unsigned				texture;
	float					top[3];
	float					width;
	float					heigth;
}							t_flag;

typedef struct				s_flag_lst
{
	t_flag					*flag;
	struct s_flag_lst		*next;
}							t_flag_lst;

typedef struct				s_wall
{
	int				start[2];
	int				end[2];
	int				next_sector;
	unsigned		b_texture;
	unsigned		m_texture;
	unsigned		t_texture;
	t_flag			*flag;
}							t_wall;

typedef	struct				s_wall_lst
{
	t_wall					*wall;
	struct s_wall_lst		*next;
}							t_wall_lst;

typedef struct				s_sector
{
	unsigned		start_wall;
	unsigned		num_walls;
	float			floor_height;
	float			ceiling_height;
	unsigned		floor_texture;
	unsigned		ceiling_texture;
}							t_sector;

typedef	struct				s_sector_lst
{
	t_sector				*sector;
	struct s_sector_lst		*next;
}							t_sector_lst;

typedef struct				s_sdl
{
	SDL_Window				*window;
	SDL_Surface				*surface;
	t_sector_lst			*sector_list;
	t_wall_lst				*wall_list;
}							t_sdl;

typedef struct				s_grid
{
	int					center[2];
	int					first_click[2];
	int					second_click[2];
	int					tst;
}							t_grid;

typedef	struct				s_select
{
	int						wall;
	int						sector;
	int						monster;
	int						pickup;
}							t_select;

typedef	struct				s_player
{
	float					position[3];
}							t_player;

typedef struct				s_core
{
	char					*file;
	t_sdl					sdl;
	SDL_Surface				*textures[NUM_TEXTURES];
	t_sector_lst			*sector_list;
	t_wall_lst				*wall_list;
	t_grid					*grid;
	t_option				option;
	t_select				*select;
	t_player				*player;
	t_monster_lst			*monster_list;
	t_pickup_lst			*pickup_list;
	Mix_Chunk				*audio[NUM_AUDIO];
	char					*ttf_path[NUM_TTF];
}							t_core;

t_bool						is_click_sector(t_core *core, float x, float y);
void						vector_init_2(int vect[2], int a, int b);
void						vector_cpy_2(int vect1[2], int vect2[2]);
void						draw_option(t_core *core, float x, float y);
void						mouse_button(t_core *core,
		SDL_MouseButtonEvent event);
void						in_map(t_core *core, float x, float y);
void						is_wall_option(t_core *core,
		SDL_MouseButtonEvent event);
void						is_sector_option(t_core *core,
		SDL_MouseButtonEvent event);
void						is_monster_option(t_core *core,
		SDL_MouseButtonEvent event);
void						is_pickup_option(t_core *core,
		SDL_MouseButtonEvent event);
void						is_right_button(t_core *core, float x, float y);
void						key_down(t_core *core, SDL_KeyboardEvent key);
void						move(t_core *core, SDL_KeyboardEvent key);
void						draw_flag_select(t_core *core);
void						draw_wall_select(t_core *core);
void						draw_player(t_core *core);
void						draw_monster(t_core *core);
void						draw_objet(t_core *core);
void						draw_sector_select(t_core *core);
void						draw_circle(SDL_Surface *screen,
		int p1[2], int p2[2], uint32_t color);
void						draw_circle_bres(SDL_Surface *screen,
		int center[2], int r, uint32_t color);
void						draw_line(SDL_Surface *screen,
		int p1[2], int p2[2], uint32_t color);
void						draw_wall(t_core *core, t_wall *wall,
		uint32_t color);
void						mset_pixel(SDL_Surface *screen,
		int x, int y, uint32_t color);
void						set_pixel(SDL_Surface *screen,
		int x, int y, uint32_t color);
void						draw_map_border(SDL_Surface *screen,
		unsigned width, uint32_t color);
void						draw_wall_list(t_core *core);
uint32_t					get_pixel(SDL_Surface *surface, float i, float j);
void						draw_texture(t_core *core, SDL_Surface *texture,
		int x, int y);
SDL_Color					int_to_rgb(uint32_t color);
SDL_Surface					*get_texte(char *txt, char *font, SDL_Color color,
		unsigned scale);
void						update_event(t_core *core);
void						paint(t_core *core);
void						mainloop(t_core *core);
void						draw_grid(t_core *core);
void						reset_first_click(t_core *core);
t_bool						init_grid(t_core *core);
void						menu_monster(t_core *core);
void						menu_objet(t_core *core);
void						textures_pickup(t_core *core, t_pickup *pickup);
void						menu_player(t_core *core);
void						write_float(t_core *core, SDL_Rect pos, float dest);
void						textures_sector(t_core *core, t_sector *sector);
char						*ft_ftoa(float nbr);
void						menu_sector(t_core *core);
void						menu_wall(t_core *core);
void						top_bottom(t_core *core, t_wall *wall);
void						middle(t_core *core, t_wall *wall);
void						print_controller_sector(t_core *core);
void						print_controller_monster(void);
void						print_controller_flag(t_core *core);
void						print_controller(t_core *core);
void						error_msg(char *str);
void						print_grid(t_grid *grid);
void						print_flag(t_flag *flag);
void						print_monster(t_monster *monster);
void						print_pickup(t_pickup *pickup);
void						print_monster_list(t_monster_lst *monster_list);
void						print_player(t_player *player);
void						print_select(t_select *select);
void						print_wall(t_wall *wall);
void						print_wall_list(t_wall_lst *wall_list);
void						print_texture(SDL_Surface *texture);
void						print_texture_list(t_core *core);
void						print_sector(t_sector *sector);
void						print_sector_list(t_sector_lst *sector_list);
void						print_controller_draw();
void						print_controller_wall(t_core *core);
t_bool						sdl_init(t_sdl *sdl);
t_bool						load_audio(t_core *core);
t_bool						init_font(t_core *core);
t_flag						*flag_cpy(t_flag *src);
t_bool						add_flag(t_core *core, int wall_idx, t_flag *flag);
void						monster_texture_change(t_core *core, int step);
t_monster					*get_monster(t_core *core, int pos);
int							get_nbr_monster(t_core *core);
t_bool						is_monster_ok(t_core *core, t_monster *monster);
int							get_sector_idx(t_core *core, t_monster *monster);
t_monster					*init_monster(t_core *core, float x, float y);
t_monster					*monster_cpy(t_monster *src);
t_bool						add_monster(t_core *core, t_monster *monster);
void						undo_last_monster(t_core *core);
void						pickup_texture_change(t_core *core, int step);
t_pickup					*init_pickup(t_core *core, float x, float y);
t_bool						add_pickup(t_core *core, t_pickup *pickup);
t_bool						is_pickup_ok(t_core *core, t_pickup *pickup);
int							get_nbr_pickup(t_core *core);
t_pickup					*get_pickup(t_core *core, int pos);
void						undo_last_pickup(t_core *core);
void						pickup_id_change(t_core *core, int step);
void						move_center(t_core *core, int step[2]);
void						set_player(t_core *core, float x, float y);
t_bool						init_player(t_core *core);
t_bool						check_header(int fd);
t_bool						load_player(t_core *core, int fd);
t_bool						load_sector_list(t_core *core, int fd);
t_bool						load_monster_list(t_core *core, int fd);
t_bool						load_pickup_list(t_core *core, int fd);
t_bool						load_wall(int fd, t_wall *buffer_wall);
t_bool						load_flag(int fd, t_wall *buffer_wall);
t_bool						load_wall_list(t_core *core, int fd);
t_bool						read_file(t_core *core, char *filename);
void						ceil_texture_change(t_core *core, int step);
void						floor_texture_change(t_core *core, int step);
void						ceil_change(t_core *core, float step);
void						floor_change(t_core *core, float step);
int							get_nbr_sector(t_sector_lst *sector_list,
		int start);
int							get_start_wall(t_core *core);
t_sector					*get_sector(t_core *core, int pos);
void						is_new_sector(t_core *core);
t_bool						is_wall_in_sector(t_core *core, int idx_wall);
void						undo_last_sector(t_core *core);
t_sector					*sector_cpy(t_sector *src);
t_bool						add_sector(t_core *core, t_sector *sector);
t_sector_lst				*get_last_sector(t_core *core);
t_bool						init_select(t_core *core);
int							count_textures(void);
void						load_wall_texture(t_core *core);
void						load_monster_texture(t_core *core);
t_bool						check_load_textures(t_core *core);
t_bool						load_textures(t_core *core);
void						load_hud_1(t_core *core);
void						load_hud_2(t_core *core);
void						load_hud_3(t_core *core);
void						load_hud_4(t_core *core);
void						load_flag_texture(t_core *core);
t_wall						*get_wall(t_core *core, int pos);
void						t_texture_change(t_core *core, int step);
void						m_texture_change(t_core *core, int step);
void						b_texture_change(t_core *core, int step);
void						next_sector_change(t_core *core);
t_wall						*wall_cpy(t_wall *src);
t_bool						add_wall(t_core *core, t_wall *wall);
void						undo_check_first(t_core *core);
void						check_sector_undo(t_core *core, int i);
void						undo_last_wall(t_core *core);
int							get_nbr_wall(t_wall_lst *wall_list, int start);
t_wall_lst					*get_last_wall(t_core *core);
t_wall_lst					*get_wall_list(t_core *core, int start);
t_bool						write_player(t_core *core, int fd);
t_bool						write_texture_2(int fd, SDL_Surface *texture,
		unsigned long *bp);
t_bool						write_texture(t_core *core, int fd);
t_bool						write_sector_list(t_core *core, int fd);
t_bool						write_monster_list_2(int fd,
		t_monster_lst *current);
t_bool						write_monster_list(t_core *core, int fd);
t_bool						write_flag_2(int fd, t_flag *flag);
t_bool						write_flag(t_flag *flag, int fd);
t_bool						write_wall_list_2(int fd, t_wall_lst *current);
t_bool						write_wall_list(t_core *core, int fd);
t_bool						write_pickup_list(t_core *core, int fd);
t_bool						write_file(t_core *core);
void						free_all(t_core *core);
void						free_monster_list(t_monster_lst *monster_list);
void						free_pickup_list(t_pickup_lst *pickup_list);
void						free_audio(t_core *core);
void						free_ttf(t_core *core);
void						free_sdl(t_core *core);
void						free_textures(t_core *core);
void						free_sector_lst(t_sector_lst *sector_list);
void						free_wall_lst(t_wall_lst *wall_list);
void						free_wall(t_wall *wall);
t_bool						float_equality(float a, float b);
t_bool						is_point_equal(int p1[2], int p2[2]);
t_bool						get_coef_droite(float *d, float *k,
		int a[2], int b[2]);
float						dist_point_droite(float point[2], t_wall *wall);
t_bool						clip_wall(float point[2], t_wall *wall);
float						scalar_product_2(float vect1[2], float vect2[2]);
t_bool						invert_matrix(float res[2][2], float m[2][2]);
t_bool						line_intersection(float res[2], float line[2][2],
		float pos[2], float dir[2]);
t_bool						check_intersection(float res[2], t_wall *wall);
t_bool						check_direction(float res[2], float ray_dir[2],
		float point[2]);
t_bool						is_intersection(t_wall *wall, float dir[2],
		float position[2]);
t_bool						is_in_sector(t_core *core, t_sector *sector,
		float point[2]);
int							get_closest_sector(t_core *core,
		t_sector_lst *sector_list,
		float x, float y);
void						init_point(float point[2], float x, float y);
void						get_closest_wall_2(float dist[2], int *res, int *i);
int							get_closest_wall(t_core *core,
		t_wall_lst *wall_list,
		float x, float y);
float						get_distance(float origin[3], float inter[2]);
int							get_closest_monster(t_monster_lst *monster_list,
		float x, float y);
int							get_closest_pickup(t_pickup_lst *pickup_list,
		float x, float y);
#endif
