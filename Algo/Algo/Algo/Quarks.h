#ifndef QUARKS_H_
#define QUARKS_H_

#include <string>
#include <vector>

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
std::vector< EColor > AllColors(); 


enum Hue
{
	kHLight,
	kHStrong
};



enum EShape
{
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
	kSzLarge,
	kSzSmall
};
std::vector< ESize > AllSizes();

std::string ShapeToString( const EShape& c );
std::string SizeToString( const ESize& s );


class BQuark
{
	EShape m_shape;
	ESize  m_size;
	EColor m_color;

public:
	BQuark( const EShape& sh,
		    const ESize&  sz,
		    const EColor& c )
		   :
	m_shape(sh),
	m_size(sz),
	m_color(c)
	{}

	EShape Shape() const { return m_shape;}
	ESize Size() const { return m_size;}
	EColor Color() const { return m_color;}
};
}// end namespace GQuarks



#endif