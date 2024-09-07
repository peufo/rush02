/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:43:12 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/08 01:36:36 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUMBER_H
# define PRINT_NUMBER_H
# include "lib.h"
# include "label.h"

void	print_number(char *number, char *dict_name);
void	print_9(t_label *labels, char *number);
void	print_99(t_label *labels, char *number);
void	print_999(t_label *labels, char *number);

#endif
