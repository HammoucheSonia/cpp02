/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:42:01 by shammouc          #+#    #+#             */
/*   Updated: 2023/01/27 19:42:03 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed :: Fixed()
{
    std :: cout  << "Default constructor called" << std :: endl;
    this->nb_fix = 0;
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

int Fixed :: getRawBits( void ) const 
{
    std :: cout << "getRawBits member function called" << std :: endl;
    return (this->nb_fix);
}

void Fixed :: setRawBits(int const raw)
{
    this->nb_fix = raw;
}

