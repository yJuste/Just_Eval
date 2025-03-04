/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2025/03/04 17:28:12 by lroussel         ###   ########.fr       */
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

// prototype
char	*get_next_line(int fd);

#endif
