/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:23:35 by shammouc          #+#    #+#             */
/*   Updated: 2023/02/01 15:23:37 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


Fixed :: Fixed() : nb_fix()
{
    std :: cout  << "Default constructor called" << std :: endl;
}

Fixed :: ~Fixed()
{
    std :: cout << "Destructor called" << std :: endl;
}

//constructeur de copie 
Fixed :: Fixed(const Fixed &src)
{
    std :: cout <<"Copy constructor called" << std :: endl;
    *this = src;
}

// opperateur d'affectation 
Fixed &Fixed :: operator=(const Fixed &other)
{
    std :: cout << "Copy assignment operator called" <<  std :: endl;
    this->nb_fix = other.getRawBits();
    return (*this);
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std :: endl;
	nb_fix= (x << nb_bits);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std :: endl;
	nb_fix = roundf(x * (1 << nb_bits));
}

int Fixed :: getRawBits( void ) const 
{
    return (this->nb_fix);
}

float Fixed :: toFloat( void ) const
{
    return ((float) nb_fix / (1 << nb_bits));
}

int Fixed :: toInt( void ) const
{
    return ((nb_fix) >> (nb_bits));
}

void Fixed :: setRawBits(int const raw)
{
    this->nb_fix = raw;
}

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}
