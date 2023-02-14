/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:23:41 by shammouc          #+#    #+#             */
/*   Updated: 2023/02/01 15:23:43 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <ostream>
#include <math.h>

class Fixed
{
    private :
        int nb_fix;
        static const int nb_bits = 8;
    public :
        Fixed(void); // constructeur par defaut 
        Fixed(const int nb);
        Fixed(const float nb);
        ~Fixed(void); // destructeur 
        Fixed(const Fixed &src);  // constructeur de copie 
        Fixed& operator=(const Fixed &other); // operateur d'affectation 
        int getRawBits(void)const;
        float toFloat( void ) const;
        int toInt( void ) const;
        void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream& out, const Fixed &other);
#endif
