/*
** tetris.h for tetris in /home/anatole.zeyen/PSU_2016_tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Feb 20 15:01:57 2017 anatole zeyen
** Last update Mon Mar  6 14:53:14 2017 anatole zeyen
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#ifndef TETRIS_H_
# define TETRIS_H_

typedef struct		s_opt
{
  char			*name;
  char			*value;
}			t_opt;

typedef struct	s_figure
{
  char		**tetris;
  int		color;
  int		width;
  int		height;
}		t_figure;

typedef struct		s_struct
{
  char			*kl;
  char			*kr;
  char			*kt;
  char			*kd;
  char			*kq;
  char			*kp;
  int			next;
  int			level;
  int			sizex;
  int			sizey;
  int			error;
}			t_struct;

void		verif_param(t_struct *infos);
t_figure	*debugmain(int ac, char **av, t_figure *figure, t_struct *infos);
char		**recreate_tetrimino(char **tetrimino, char **figure, int x, int y);
char		**transform_tetrimino(char **tetrimino);
int		add_tetrimino(char **map, t_figure figure, int var, int sizey);
char		**place_map(char **map, int sizex, int sizey);
char		**place_borders(char **map, int j, int y, int x);
char		**create_map(char **map, int x, int y);
void		init();
void		init2();
void		init3();
void		init4();
int		debug(char **av);
char		*my_strcat(char *path, char *name);
char		*recreate_name(char *name);
int		is_nbr(char *str);
int		my_strcmp(char *s1, char *s2);
int		get_size(char *av1, int size);
int		my_putnbr(int nb);
int		maloc_str(char *str, int x, char charact);
int		word_count(char *str, char charact);
char		**my_str_to_wordtab(char *str, char charact);
void		my_putstr(char *str);
void		my_putchar(char c);
char		*my_strdup(char *src);
int		len(char *str);
int		my_getnbr(char *str);
int		my_space(int c);
int		numbers(int c);
int		full_opt(t_opt *args, int index_av, char **av, int arg_pos);
int		count_x_in_str(char *str, char c);
char		*before_equal(char *str);
char		*after_equal(char *str);
t_figure	my_prompt_figure(char **tab, char *name, int error, t_figure figure);
char		**sort_d_name(char *str, char *av1);
int		my_parsing(char **tab);
t_figure 	*my_display_array(char **array, char *path, t_figure *figure);
char		**sort_d_name(char *str, char *av1);
void    	swap_elem(char **index1, char **index2);
int		verif_figure(char **tab, int lines);
int		my_fakestrlen(char *str);
char    	**please_sort_this_array(char **array, int size, char *path);
t_figure	prompt_one_file(char *name, t_figure figure);
int		is_tetrimino(char *name);
int		check_double_arg(t_opt *args, int nb);
t_struct	*init_infos(t_struct *infos, char **av);

#endif /* !TETRIS_H_ */
#endif /* !READ_SIZE */
