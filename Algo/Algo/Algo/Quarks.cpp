#include "Quarks.h"

namespace GQuarks
{
std::string ColorToString( const EColor& c )
{
	switch(c)
	{
	case kCPink:  return "Pink";
	case kCRed: return "Red";
	case kCGreen: return "Green";
	case kCYellow: return "Yellow";
	case kCLightBlue: return "LightBlue";
	case kCDarkBlue: return "DarkBlue";
	default: throw "Unknown color encountered";
	}
}

std::vector< EColor > AllColors()
{
	EColor cs[] = {kCPink, kCRed, kCGreen, kCYellow, kCLightBlue,kCDarkBlue};
	std::vector<EColor> rv(cs,cs+sizeof( cs) / sizeof(cs[0]));
	return rv;
}



std::string ShapeToString( const EShape& s )
{
	switch(s) 
	{
	case kSCircle: return "Circle";
	case 	kSTriangle: return "Triangle";
	case 	kSOval: return "Oval";
	case 	kSPear: return "Pear";
	case 	kSDiamond: return "Diamond";
	case 	kSSquare: return "Square";
	case 	kSSemiCircle: return "SemiCircle";
	case 	kSRectangle: return "Rectangle";
	case 	kSStar: return "Star";
	case 	kSHeart: return "Heart";
	case 	kSArch: return "Arch";
	default: throw "Unknown shape encountered";
	}
}

std::vector< EShape > AllShapes()
{
	EShape ss[] = {
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
	kSArch};

	std::vector< EShape > rv(ss,ss+sizeof(ss) / sizeof(ss[0]));
	return rv;
}



std::string SizeToString( const ESize& s )
{
	switch( s)
	{
	case kSzLarge: return "Large";
	case kSzSmall: return "Small";
	default: throw "unknown size encountered";
	}
}

std::vector< ESize> AllSizes()
{
	ESize ss[] = { kSzLarge, kSzSmall };
	std::vector<ESize> rv(ss,ss+1);
	return rv;
}


}