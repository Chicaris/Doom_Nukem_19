/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 08:45:11 by hde-moff          #+#    #+#             */
/*   Updated: 2019/11/20 14:48:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <errno.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xD20A2B
# define BLUE	0x000080
# define GREEN	0x01FE4D
# define AMASK 0xFF000000
# define RMASK 0x00FF0000
# define GMASK 0x0000FF00
# define BMASK 0x000000FF
# define CLIP_CENTER		0x0
# define CLIP_UP			0x1
# define CLIP_DOWN			0x2
# define CLIP_RIGHT			0x4
# define CLIP_LEFT			0x8
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define M_SENSITIVITY 0.00375f
# define MOVE_SPEED 0.05f
# define EPSILON	(1.0E-8)
# define STEP 128
# define ITEM_NBR 8
# define DEBUG_FDF_MASK 0x1
# define VSTEP  128
# define VJUMP  256
# define DELTA_T 0.1
# define FPS_DT  24
# define FXY	 5.0
# define GRAVITY 256.0
# define ZMIN	64
# define THREAD_NUMBER 32
# define INTERSECT_TOL 1

typedef enum	e_bool
{
	true, false
}				t_bool;

typedef enum	e_mode
{
	camera, player
}				t_mode;

typedef enum	e_status
{
	menu, game, pause_menu, game_over, you_win
}				t_status;

typedef struct	s_line
{
	float			vect[2][3];
	int				visible;
	struct s_line	*next;
}				t_line;

typedef struct	s_monster
{
	unsigned			texture;
	int					sector_idx;
	float				start[3];
	float				end[3];
	float				ceil;
	float				floor;
	float				center[3];
	float				lookat[3];
}				t_monster;

typedef struct	s_pickup
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
}				t_pickup;

typedef	struct	s_monster_lst
{
	t_monster				*monster;
	struct s_monster_lst	*next;
}				t_monster_lst;

typedef struct	s_pickup_lst
{
	t_pickup					*pickup;
	struct s_pickup_lst			*next;
}				t_pickup_lst;

typedef struct	s_sector
{
	unsigned			start_wall;
	unsigned			num_walls;
	float				floor_height;
	float				ceiling_height;
	unsigned			floor_texture;
	unsigned			ceiling_texture;
}				t_sector;

typedef struct	s_flag
{
	unsigned				texture;
	float					top[3];
	float					width;
	float					heigth;
}				t_flag;

typedef struct	s_wall
{
	int					start[2];
	int					end[2];
	int					next_sector;
	unsigned			b_texture;
	unsigned			m_texture;
	unsigned			t_texture;
	t_flag				*flag;
}				t_wall;

typedef struct	s_wall_list
{
	int					visible;
	int					sector_idx;
	float				intersect[2];
	float				floor;
	float				ceil;
	t_wall				wall;
	t_line				*lines;
	struct s_wall_list	*next;
}				t_wall_list;

typedef struct	s_sect_list
{
	int					idx;
	int					visible;
	t_sector			sector;
	t_wall_list			*wall_list;
	struct s_sect_list	*next;
}				t_sect_list;

typedef struct	s_level_data
{
	unsigned		num_sectors;
	t_sector		*sectors;
	unsigned		num_walls;
	t_wall			*walls;
	unsigned		num_textures;
	SDL_Surface		**textures;
	unsigned		num_audio;
	Mix_Chunk		**samples;
	float			origin_player[3];
	t_monster_lst	*monster_list;
	t_pickup_lst	*pickup_list;
	unsigned		num_ttf;
	char			*ttf_path[1024];
}				t_level_data;

typedef struct	s_sdl
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	int					x_center;
	int					y_center;
}				t_sdl;

typedef struct	s_mouse
{
	int				last[2];
	int				curr[2];
	int				button;
	t_bool			status;
}				t_mouse;

typedef struct	s_camera
{
	int			projection;
	float		fov_x;
	float		fov_y;
	float		focal;
	float		origin[3];
	float		lookat[3];
	float		up[3];
	float		speed[3];
}				t_camera;

typedef struct	s_item
{
	int			item_id;
	char		*item_name;
	int			quantity;
}				t_item;

typedef struct	s_weapon
{
	int					w_id;
	int					posessed;
	int					w_status;
	int					w_rof;
	int					w_rload_spd;
	int					w_range;
	int					w_mag_size;
	int					w_magazine;
	int					w_fire_spr;
	int					w_reload_spr;
	int					w_empty_spr;
	int					rest_sprs;
	int					fire_sprs;
	int					empty_sprs;
	int					rload_sprs;
	int					fire_spr_nbr;
	int					empty_spr_nbr;
	int					rload_spr_nbr;

}				t_weapon;

typedef struct	s_item_ls
{
	t_item			*item_list;
	t_weapon		*weapon_list;
}				t_item_ls;

typedef struct	s_player
{
	t_item			*inventory;
	int				life;
	t_weapon		*gun;
	int				active_wp;
}				t_player;

typedef struct	s_core
{
	char			*file;
	t_sdl			sdl;
	t_level_data	level;
	t_sect_list		*world;
	t_camera		camera;
	int				sector_in;
	t_mouse			mouse;
	t_mode			mode;
	int				fly_mode;
	int				debug;
	t_player		player;
	t_item_ls		item_ls;
	t_status		game_status;
	int				selected;
	int				door_status;
	float			step_door;
	int				music_status;
	int				sky_status;
	int				step_status;
	SDL_TimerID		timer;
}				t_core;

typedef struct	s_raycast_args
{
	pthread_t		thread;
	t_core			*core;
	int				x_begin;
	int				n_steps;
}				t_raycast_args;

void			move_monster_list(t_core *core);
void			change_monster(t_core *core, t_monster *monster);
void			init_monster_list(t_core *core);
t_monster		*monster_cpy(t_monster *src);
t_bool			add_monster(t_level_data *level_data, t_monster *monster);
int				get_monster_nbr(t_monster_lst *monster_list);
void			delete_monster(t_core *core, int idx);
void			delete_monster_2(t_core *core, t_monster *monster);
uint32_t		get_pixel(SDL_Surface *texture, float x, float y);
t_line			*init_lines(t_wall wall, float floor, float ceil);
void			door_move(t_core *core);
t_wall_list		*create_wall(t_core *core, t_sector sector, int idx);
float			get_distance(float	origin[3], float inter[2]);
void			add_wall_end(t_core *core, t_sector sector,
					int wall_idx, t_wall_list *list, float res[2]);
void			concat_wall_list(t_wall_list *begin, t_wall_list *end);
void			sort_wall_list(t_core *core, t_wall_list *list);
void			swap_wall(t_wall_list *a, t_wall_list *b);
t_wall_list		*init_walls(t_core *core, int idx);
t_wall			*wall_cpy(t_wall *src);
t_bool			wall_equality(t_wall *dest, t_wall *src);
void			line_projection(t_core *core, t_line *line);
t_bool			init_camera(t_core *core);
void			set_projection(t_core *core, int proj);
void			camera_move(t_core *core, float vect[3]);
void			error_msg(t_core *core, char *msg);
void			print_menu(void);
t_bool			load_level_data(t_core *core);
t_bool			init_world(t_core *core);
t_sect_list		*get_sector_in(t_core *core);
t_bool			init_camera_world(t_core *core);
void			camera_to_world(t_camera *self, float matrix[4][4]);
void			world_to_camera(t_camera *self, float matrix[4][4]);
t_flag			*flag_cpy(t_flag *src);
void			fire(t_core *core);
t_wall			*get_closest_wall(t_core *core, int curr_sector,
					float i[3], float ray_dir[3]);
uint32_t		get_pixel_monster(t_core *core, t_monster *closest_monster,
					float intersection[3]);
uint32_t		get_pixel_pickup(t_core *core, t_pickup *closest_pickup,
					float intersection[3]);
uint32_t		get_final_color(t_core *core, int cur_sector,
					float ray_dir[3]);
void			init_raycast(float ray_dir[3], int x[2], t_core *core,
					float matrix[4][4]);
void			*raycast(void *args);
void			get_texture_offset(t_wall *closest_wall, float intersection[3],
					float texture_offset[2], t_sector *sector);
void			get_texture_offset_monster(t_monster *closest_monster,
					float intersection[3], float texture_offset[2]);
void			gtop(t_pickup *pickup, float intersection[3],
					float texture_offset[2]);
uint32_t		get_sky_rgb(float ray_dir[3], float texture_offset[3],
					t_sector *sector, t_core *core);
t_wall			*ray_sector(t_core *core, int s_idx, float inter[3],
					float ray[3]);
uint32_t		get_world_rgb(t_core *core, int cur_sector, float ray_dir[3],
					float i[3]);
void			norminette_vect(float dest[23][3], float a[3], float b[3],
					float c[3]);
t_bool			clip_wall(float intersection[3], t_wall *current_wall,
					t_sector *sector);
uint32_t		get_rgb(t_core *core, float offset[3], t_wall *wall,
					SDL_Surface *texture);
uint32_t		get_pixel_door(SDL_Surface *surface, float offset[2],
					float width, float height);
uint32_t		get_door_rgb(t_core *core, t_wall *wall, float intersection[3],
					t_sector *sector);
t_bool			check_intersection(float res[2], t_wall wall);
t_bool			check_direction(float res[2], t_camera camera);
t_bool			is_intersection_2(t_wall wall, t_camera camera, float dir[3],
					float res[2]);
t_bool			is_intersection(t_wall wall, t_camera camera, float dir[3],
					float res[2]);
int				get_sector(t_core *core);
t_bool			is_inside(t_core *core, int idx_sector);
t_pickup		*ray_pickup(t_core *core, float intersection[3], float ray[3]);
t_bool			clip_pickup(float intersection[3], t_pickup *pickup);
t_bool			check_objet(t_core *core, t_pickup *item, float pos[3],
					float intersection[3]);
t_bool			check_list_objet(t_core *core, float pos[3]);
t_bool			check_door_wall(t_core *core, t_wall *wall, float pos[3],
					float intersection[3]);
t_bool			check_door(t_core *core, float pos[3]);
void			move_fall(t_core *core);
void			move_floor(t_core *core, float underflow[3]);
void			move(t_core *core);
void			camera_step(t_camera *camera, float step_size);
void			straff_key(t_camera *camera, float step_size);
void			up_key(t_core *core, int step);
void			update_camera_pos(t_camera *camera, float offset[3]);
void			free_lines(t_line *lines);
void			free_wall_list(t_wall_list *wall_list);
void			free_world(t_core *core);
void			free_player(t_core *core);
void			free_all(t_core *core);
void			free_sdl(t_core *core);
void			free_monster_list(t_monster_lst *monster_list);
void			free_pickup_list(t_pickup_lst *pickup_list);
void			free_wall(t_wall *wall);
void			free_level_data(t_core *core);
t_bool			load_level_data(t_core *core);
t_bool			load_player(int fd, t_level_data *level_data);
t_bool			load_monster_list(t_level_data *level_data, int fd);
t_bool			load_pickup_list(t_level_data *level_data, int fd);
t_bool			load_sectors(int fd, t_level_data *level_data);
t_bool			load_walls(int fd, t_level_data *level_data);
t_bool			load_textures(int fd, t_level_data *level_data);
t_bool			load_audio(int fd, t_level_data *level_data);
t_bool			load_ttf(int fd, t_level_data *level_data);
t_bool			init_core(t_core *core);
void			matrix_translation(float dst[4][4], float vec[3]);
void			matrix_rotation(float dst[4][4], t_camera *camera);
t_bool			float_equality(float a, float b);
void			*raycast(void *args);
t_bool			check_direction(float res[2], t_camera camera);
t_bool			check_intersection(float res[2], t_wall wall);
t_bool			line_intersection(float res[2], float line[2][2],
					float pos[3], float dir[3]);
void			line_clip(t_core *core, t_line *line);
void			camera_step(t_camera *camera, float step_size);
void			straff_key(t_camera *camera, float step_size);
void			up_key(t_core *core, int zoom);
t_bool			is_intersection(t_wall wall, t_camera camera,
					float dir[3], float res[2]);
t_bool			is_intersection_2(t_wall wall, t_camera camera,
					float dir[3], float res[2]);
t_bool			is_inside(t_core *core, int idx_sector);
float			scalar_product_3(float a[3], float b[3]);
float			scalar_product_2(float a[2], float b[2]);
t_bool			invert_matrix(float res[2][2], float m[2][2]);
float			get_distance_vect(float a[3], float b[3]);
t_bool			get_lambda(float *lambda, float ray_origin[3],
					float ray_dir[3], t_wall *wall);
t_bool			get_lambda_monster(float *lambda, float ray_origin[3],
					float ray_dir[3], t_monster *monster);
t_bool			glp(float *lambda, float ray_origin[3], float ray_dir[3],
					t_pickup *pickup);
void			rotate_world_z(t_camera *self, float theta);
void			rotate_camera_right(t_camera *self, float theta);
void			move_camera(t_camera *self, float distance);
void			move(t_core *core);
t_bool			hit_floor(t_core *core, float	intersection[3],
						float ray_dir[3], float z, int sector_idx);
t_bool			is_inside_sector(t_core *core, int sector_idx,
					float intersection[3], float ray_dir[3]);
t_bool			is_intersection_sector(t_wall wall, t_camera camera,
					float dir[3], float position[3]);
t_bool			get_z_intersection(float res[3], float ray[3], float z,
					float origin[3]);
t_bool			check_mouvement(t_core *core, float position[3],
					int sector_idx);
t_bool			is_inside_maze(t_core *core, float position[3]);
t_bool			is_inside_maze_monster(t_core *core,
					float position[3]);
t_bool			clip_monster(float	intersection[3], t_monster *monster);
t_monster		*ray_monster(t_core *core, float intersection[3], float ray[3]);
void			get_texture_offset_monster(t_monster *closest_monster,
					float intersection[3], float texture_offset[2]);
t_wall			*ray_sector(t_core *core, int sector_idx, float intersection[3],
					float ray[3]);
uint32_t		get_world_rgb(t_core *core, int cur_sector, float ray_dir[3],
					float closest_intersection[3]);
void			get_texture_offset(t_wall *closest_wall, float intersection[3],
					float texture_offset[2], t_sector *sector);
void			gtop(t_pickup *pickup, float intersection[3],
					float texture_offset[2]);
void			update_life(t_core *core, int step);
void			floor_is_lava(t_core *core);
t_bool			init_player(t_core *core);
void			update_player(t_core *core, int item_id);
t_bool			init_items(t_core *core);
t_bool			pick_up_item(t_core *core, int item_id);
t_bool			init_weapon(t_core *core);
void			change_weapon(t_core *core, int modif);
void			reload_gun(t_core *core);
t_pickup		*ray_pickup(t_core *core, float intersection[3], float ray[3]);
t_bool			add_pickup(t_level_data *level_data, t_pickup *pickup);
void			init_pickup_list(t_core *core);
void			check_pickup_proximity(t_core *core, t_pickup *pickup);
void			delete_pickup(t_core *core, t_pickup *pickup);
void			check_pickup_proximity_lst(t_core *core);
t_pickup		*pickup_cpy(t_pickup *src);
t_bool			init_sound(t_core *core);
void			free_all(t_core *core);
void			free_lines(t_line *lines);
void			free_wall_list(t_wall_list *wall_list);
void			set_pixel(SDL_Surface *screen, int x, int y, uint32_t color);
void			paint(t_core *core);
void			exit_seq(t_core *core);
t_bool			sdl_init(t_core	*core);
void			mainloop(t_core *core);
void			draw(t_core *core, t_line *line, int color);
void			draw_line(t_core *core, t_line *line, float matrix[4][4]);
void			draw_wall(t_core *core, t_wall_list *wall, float matrix[4][4]);
void			draw_sector(t_core *core, t_sect_list *sector,
					float matrix[4][4]);
void			display_hud(t_core *core);
void			fire_weapon(t_core *core, int status);
void			display_you_win(t_core *core);
void			display_game_over(t_core *core);
void			display_menu(t_core *core);
void			display_pause_menu(t_core *core);
void			display_ammo(t_core *core, int active);
void			display_play(t_core *core);
void			display_quit(t_core *core);
void			display_gun(t_core *core, int active);
SDL_Color		int_to_rgb(uint32_t color);
SDL_Surface		*get_texte(char *txt, char *font, SDL_Color color,
					unsigned scale);
void			key_down(t_core *core, SDL_KeyboardEvent key);
void			key_arrow(t_core *core, SDL_KeyboardEvent key);
void			key_move(t_core *core, SDL_KeyboardEvent key);
void			key_down3(t_core *core, SDL_KeyboardEvent key);
void			key_return(t_core *core, SDL_KeyboardEvent key);
void			mouse_down(t_core *core, SDL_MouseButtonEvent event);
void			mouse_up(t_core *core, SDL_MouseButtonEvent event);
void			mouse_motion(t_core *core, SDL_Event event);
void			mouse_wheel(t_core *core, SDL_MouseWheelEvent event);
void			mouse_update(t_core *core);
#endif
