#include "Quarks.h"

#include <boost/archive/tmpdir.hpp>

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>


namespace GQuarks
{
std::string ColorToString( const EColor& c )
{
	switch(c)
	{
	case kCNone: return "None";
	case kCPink:  return "Pink";
	case kCRed: return "Red";
	case kCGreen: return "Green";
	case kCYellow: return "Yellow";
	case kCLightBlue: return "LightBlue";
	case kCDarkBlue: return "DarkBlue";
	default: return "None";
	}
}


EColor StringToColor( const std::string& s )
{
	if( s == "None" ) return kCNone;
	if( s == "Pink" ) return kCPink;
	if( s ==  "Red" ) return kCRed;
	if( s ==  "Green" ) return kCGreen;
	if( s ==  "Yellow" ) return kCYellow;
	if( s ==  "LightBlue" ) return kCLightBlue;
	if( s ==  "DarkBlue" ) return kCDarkBlue;
	return kCNone;
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
	case kSNone: return "None";
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
	default: return "None";
	}
}

EShape ShapeToString( const std::string& s )
{
	if( s == "None" ) return kSNone;
	if( s ==  "Circle" ) return kSCircle;
	if( s == "Triangle") return kSTriangle;
	if( s ==  "Oval" ) return kSOval;
	if( s ==  "Pear" ) return kSPear;
	if( s ==  "Diamond" ) return kSDiamond;
	if( s ==  "Square" ) return kSSquare;
	if( s == "SemiCircle" ) return kSSemiCircle;
	if( s ==  "Rectangle" ) return kSRectangle;
	if( s ==  "Star" ) return kSStar;
	if( s ==  "Heart" ) return kSHeart;
	if( s ==  "Arch" ) return kSArch;
	return kSNone;
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
	case kSzNone: return "None";
	case kSzLarge: return "Large";
	case kSzSmall: return "Small";
	default: return "None";
	}
}

ESize StringToSize( const std::string& s )
{
	if( s ==  "None" ) return kSzNone;
	if( s ==  "Large" ) return kSzLarge;
	if( s ==   "Small" ) return kSzSmall;
	return kSzNone;
}




std::vector< ESize> AllSizes()
{
	ESize ss[] = { kSzLarge, kSzSmall };
	std::vector<ESize> rv(ss,ss+1);
	return rv;
}


void
restore_quark(BQuark &q, const char * filename)
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);

    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(q);
}

void 
save_quark(const BQuark &q, const char * filename){
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(q);
}




}//end namespace