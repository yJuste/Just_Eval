/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by lroussel                           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

//	---------- MACROS -----------

// ne pas oublier le ifndef pour le buffer_size.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//	---------- Prototype ----------

char	*get_next_line(int fd);

#endif
