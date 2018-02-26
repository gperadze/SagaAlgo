#ifndef QUARKS_H_
#define QUARKS_H_

#include <string>
#include <vector>


#include <iomanip>
#include <iostream>
#include <fstream>


#include <boost/serialization/string.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/assume_abstract.hpp>



namespace GQuarks
{
enum EColor
{
	kCNone,
	kCPink,
	kCRed,
	kCGreen,
	kCYellow,
	kCDarkBlue,
	kCLightBlue
};

std::string ColorToString( const EColor& c );
EColor StringToColor( const std::string& c );

std::vector< EColor > AllColors(); 


enum Hue
{
	kHNone,
	kHLight,
	kHStrong
};



enum EShape
{
	kSNone,
	kSCircle,
	kSTriangle,
	kSOval,
	kSPear,
	kSDiamond,
	kSSquare,
	kSSemiCircle,
	kSRectangle,
	kSStar,
	kSHeart,
	kSArch
};
std::vector< EShape > AllShapes();

enum ESize
{
	kSzNone,
	kSzLarge,
	kSzSmall
};
std::vector< ESize > AllSizes();

std::string ShapeToString( const EShape& c );
std::string SizeToString( const ESize& s );

EShape StringToShape( const std::string& s );
ESize StringToSize( const std::string& s );


class BQuark
{
	std::string m_shape;
	std::string m_size;
	std::string m_color;

    friend class boost::serialization::access;
    friend std::ostream & operator<<(std::ostream &os, const BQuark& quark);

    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */)
	{
        ar  & BOOST_SERIALIZATION_NVP(m_shape)
            & BOOST_SERIALIZATION_NVP(m_size )
            & BOOST_SERIALIZATION_NVP(m_color);
	}

public:
	BQuark(){};

	BQuark( const EShape& sh,
		    const ESize&  sz,
		    const EColor& c )
		   :
	m_shape(ShapeToString( sh) ),
	m_size(SizeToString( sz) ),
	m_color(ColorToString( c ) )
	{}

	EShape Shape() const { return StringToShape( m_shape); }
	ESize Size() const { return StringToSize( m_size); }
	EColor Color() const { return StringToColor( m_color);}
};

void
restore_quark(BQuark &q, const char * filename);

void 
save_quark(const BQuark &q, const char * filename);

}// end namespace GQuarks



#endif