/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:41:28 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:41:29 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# ifdef __linux__
#  define ESC				65307
#  define MOUSE_SCROLL_UP	5
#  define MOUSE_SCROLL_DOWN	4
#  define ARROW_UP			65362
#  define ARROW_DOWN		65364
#  define ARROW_LEFT		65361
#  define ARROW_RIGHT		65363
#  define SPACE				32

#  define NUM_PLUS			65451
#  define NUM_MINUS			65453

#  define MAIN_PLUS			61
#  define MAIN_MINUS		45

#  define MAIN_B			98
#  define MAIN_R			114
#  define MAIN_G			103
#  define MAIN_T			116
#  define MAIN_I			105
#  define MAIN_P			112
#  define MAIN_C			99

#  define ONE				49
#  define TWO				50
#  define THREE				51
#  define FOUR				52
#  define FIVE				53
#  define SIX				54
#  define SEVEN				55
#  define EIGHT				56
#  define NINE				57
#  define NUM_ONE			65436
#  define NUM_TWO			65433
#  define NUM_THREE			65435
#  define NUM_FOUR			65430
#  define NUM_FIVE			65437
#  define NUM_SIX			65432
#  define NUM_SEVEN			65429
#  define NUM_EIGHT			65431
#  define NUM_NINE			65434

# else
#  define ESC				53
#  define MOUSE_SCROLL_UP	4
#  define MOUSE_SCROLL_DOWN	5
#  define ARROW_UP			126
#  define ARROW_DOWN		125
#  define ARROW_LEFT		123
#  define ARROW_RIGHT		124
#  define SPACE				49

#  define NUM_PLUS			69
#  define NUM_MINUS			78

#  define MAIN_PLUS			24
#  define MAIN_MINUS		27

#  define MAIN_B			11
#  define MAIN_R			15
#  define MAIN_G			5
#  define MAIN_T			17
#  define MAIN_I			34
#  define MAIN_P			35
#  define MAIN_C			8

#  define ONE				18
#  define TWO				19
#  define THREE				20
#  define FOUR				21
#  define FIVE				23
#  define SIX				22
#  define SEVEN				26
#  define EIGHT				28
#  define NINE				25
#  define NUM_ONE			83
#  define NUM_TWO			84
#  define NUM_THREE			85
#  define NUM_FOUR			86
#  define NUM_FIVE			87
#  define NUM_SIX			88
#  define NUM_SEVEN			89
#  define NUM_EIGHT			91
#  define NUM_NINE			92

# endif
#endif
