/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:43:19 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 16:51:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)

# define TPUTS(x, y) tputs(tgetstr(((TOSTRING(x))), &area), y, ft_putc)

# define BOLD md
# define BLINK mb
# define UL us7
# define VR mr
# define STOP me

# define UP up
# define DOWN do
# define RIGHT nd
# define LEFT le

# define CURINV vi
# define CURNORM ve
# define CLEAR cl

# define SP 32
# define NL 10
# define DEL 127

typedef struct termios	t_termios;
/*
** tcflag_t			c_iflag;       modes d'entrée
** tcflag_t			c_oflag;       modes de sortie
** tcflag_t			c_cflag;       modes de contrôle
** tcflag_t			c_lflag;       modes locaux
** cc_t				c_cc[NCCS];    caractères de contrôle
*/

typedef struct winsize	t_winsize;
/*
** unsigned short	ws_row;
** unsigned short	ws_col;
** unsigned short	ws_xpixel;
** unsigned short	ws_ypixel;
**
** TIOCGWINSZ     struct winsize *argp
** 		Récupère la taille de la fenêtre.
*/

typedef struct			s_elem
{
	char			*name;
	int				selected;
	struct s_elem	*left;
	struct s_elem	*right;
	struct s_elem	*next;
	struct s_elem	*prev;
}						t_elem;

typedef struct			s_env
{
	t_elem			*lst;
	t_elem			*cursor;
	t_termios		term;
	t_winsize		win;
	int				list_len;
	int				max_len;
	int				screen_row;
	int				screen_col;
	int				fd;
}						t_env;

typedef struct			s_pattern
{
	const char		buffer[5];
	void			(*f)(t_env *e);
}						t_pattern;

/*
**		TERM
*/

int						init_term(t_env *e);
int						reset_term(t_env *e);
void					exit_error(char *msg);
void					exit_free(t_env *e);
void					exit_result(t_elem *lst);
void					check_for_signals();
static void				signal_handler(int signum);

/*
**		LIST
*/

void					create_list(t_env *e, char **av, int ac);
void					print_list(t_elem *lst, int rev);

/*
**		KEYBOARD
*/

void					read_keyboard(t_env *e, char buffer[4], char *area);
void					erase_link(t_env *e);

/*
**		SCREEN DISPLAY
*/

int						display_on_screen(t_env *e);
int						ft_putc(int c);
void					padding(int n, int fd);
void					print_list_on_screen(t_env *e, char *area);
void					update_screen(t_env *e, char *area);
void					update_left_right(t_env *e);

#endif
