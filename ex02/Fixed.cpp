/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:17 by shammouc          #+#    #+#             */
/*   Updated: 2023/02/01 15:22:21 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"
#include <iostream>


Fixed :: Fixed() : nb_fix()
{
}

Fixed :: ~Fixed()
{
}

//constructeur de copie 
Fixed :: Fixed(const Fixed &src)
{
    *this = src;
}

// opperateur d'affectation 
Fixed &Fixed :: operator=(const Fixed &other)
{
    this->nb_fix = other.getRawBits();
    return (*this);
}

Fixed::Fixed(const int x)
{
	nb_fix= (x << nb_bits);
}

Fixed::Fixed(const float x)
{
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

//////////Operateurs arithmetiques//////////////////

Fixed Fixed::operator+(const Fixed &c)
{
    nb_fix += c.nb_fix;
    return *this;
}

Fixed Fixed::operator-(const Fixed &c)
{
    nb_fix -= c.nb_fix;
    return *this;
}

Fixed Fixed::operator*( const Fixed &rhs )
{
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( const Fixed &rhs )
{
    return Fixed( this->toFloat() / rhs.toFloat() );
}

Fixed &Fixed::operator++()
{
    ++this->nb_fix;
    return (*this);
}

Fixed &Fixed::operator--()
{
    --this->nb_fix;
    return (*this);
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp.nb_fix = this->nb_fix--;
    return tmp;
}

Fixed Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp.nb_fix = this->nb_fix++;
    return tmp;
}
///###################################################///


/// Operateurs de comparaison///

bool Fixed :: operator>( const Fixed &rhs ) const
{
    return this->getRawBits() > rhs.getRawBits();
}
bool Fixed  :: operator<( const Fixed &rhs ) const
{
    return this->getRawBits() < rhs.getRawBits();
}
bool Fixed :: operator>=( const Fixed &rhs ) const
{
    return this->getRawBits() >= rhs.getRawBits();
}
bool Fixed :: operator<=( const Fixed &rhs ) const
{
    return this->getRawBits() <= rhs.getRawBits();
}
bool Fixed :: operator==( const Fixed &rhs ) const
{
    return this->getRawBits() == rhs.getRawBits();
}
bool Fixed :: operator!=( const Fixed &rhs ) const
{
    return this->getRawBits() != rhs.getRawBits();
}
///#######################################//////

//Min et Max /////
Fixed Fixed :: min(Fixed a, Fixed b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed Fixed :: max(Fixed a, Fixed b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

//#################################///

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}
