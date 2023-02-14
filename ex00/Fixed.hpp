/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:42:09 by shammouc          #+#    #+#             */
/*   Updated: 2023/01/27 19:42:11 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <ostream>

class Fixed
{
    private :
        int nb_fix;
        static const int nb_bits = 8;
    public :
        Fixed(void); // constructeur par defaut 
        ~Fixed(void); // destructeur 
        Fixed(const Fixed &src);  // constructeur de copie 
        Fixed& operator=(const Fixed &other); // operateur d'affectation 
        int getRawBits(void)const;
        void setRawBits(int const raw);
};

#endif