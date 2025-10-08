#include <Arduino.h>

#define USB_SERIAL Serial

#include <MapScreen_T4.h>

#include <TFT_eSPI.h>

#include <LilyGo_AMOLED.h>

#include "fonts/NotoSansBold36.h"
#include "fonts/Final_Frontier_28.h"

extern const uint16_t lily_wraysbury_N[];
extern const uint16_t lily_wraysbury_W[];
extern const uint16_t lily_wraysbury_SW[];
extern const uint16_t lily_wraysbury_S[];
extern const uint16_t lily_wraysbury_SE[];
extern const uint16_t lily_wraysbury_All[];

extern const uint16_t lily_home_Centre[];
extern const uint16_t lily_home_All[];

extern const uint16_t lily_vobster_Centre[];
extern const uint16_t lily_vobster_All[];

extern const uint16_t lily_all_other_areas_Centre[];
extern const uint16_t lily_all_other_areas_All[];

const MapScreen_ex::geo_map MapScreen_T4::s_maps[] =
{
  [0] = { .mapData = lily_wraysbury_N, .label="North", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.5503, .mapLongitudeRight = -0.5473, .mapLatitudeBottom = 51.4613}, // -0.5503,51.4613,-0.5473,51.4627
  [1] = { .mapData = lily_wraysbury_W, .label="West", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.5501, .mapLongitudeRight = -0.5471, .mapLatitudeBottom = 51.4606},  // -0.5501,51.4606,-0.5471,51.462
  [2] = { .mapData = lily_wraysbury_SW, .label="South West", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.5494, .mapLongitudeRight = -0.5464, .mapLatitudeBottom = 51.4597}, // 0.5494,51.4597,-0.5464,51.4611
  [3] = { .mapData = lily_wraysbury_S, .label="South", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.5491, .mapLongitudeRight = -0.5461, .mapLatitudeBottom = 51.4591}, // -0.5491,51.4591,-0.5461,51.4605
  [4] = { .mapData = lily_wraysbury_SE, .label="South East", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.548, .mapLongitudeRight = -0.545, .mapLatitudeBottom = 51.4588}, //  -0.548,51.4588,-0.545,51.4602
  [5] = { .mapData = lily_wraysbury_All, .label="All", .backColour=TFT_BLACK, .backText="", .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.5517, .mapLongitudeRight = -0.5437, .mapLatitudeBottom = 51.4588}, //  -0.5517,51.4588,-0.5437,51.4626
  [6] = { .mapData = nullptr, .label="Canoe", .backColour=TFT_CYAN, .backText="Canoe",.surveyMap=true, .swapBytes=false, .mapLongitudeLeft = -0.54910, .mapLongitudeRight = -0.54880, .mapLatitudeBottom = 51.46190}, // Canoe area - check
  [7] = { .mapData = nullptr, .label="Sub",  .backColour=TFT_CYAN, .backText="Sub",.surveyMap=true, .swapBytes=false, .mapLongitudeLeft = -0.54931, .mapLongitudeRight = -0.54900, .mapLatitudeBottom = 51.4608}, // Sub area - check
  [8] = { .mapData = lily_home_Centre, .label="Home",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.2889, .mapLongitudeRight = -0.2866, .mapLatitudeBottom = 51.3912}, // map top 51.3923
  [9] = { .mapData = lily_home_All, .label="All",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -0.2951, .mapLongitudeRight = -0.2817, .mapLatitudeBottom = 51.3882, }, // map top 51.3944
  [10] = { .mapData = lily_vobster_Centre, .label="Vobster",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -2.4255, .mapLongitudeRight = -2.4202, .mapLatitudeBottom = 51.24465}, // map top 51.2472  origianal bot = 51.2448
  [11] = { .mapData = lily_vobster_All, .label="All",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = -2.427, .mapLongitudeRight = -2.4202, .mapLatitudeBottom = 51.2447},  // map top 51.2479

  // old bottom: 51.06601   last: 51.06511112 
  [12] = { .mapData = lily_all_other_areas_Centre, .label="Out-To-Sea",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = 1.269333, .mapLongitudeRight = 1.272333, .mapLatitudeBottom = 51.06538078},
 // [13] = { .mapData = lily_all_other_areas_All, .label="All",  .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = 1.269333, .mapLongitudeRight = 1.272333, .mapLatitudeBottom = 51.06538078},

//  [13] = { .mapData = lily_all_other_areas_All, .label="All", .backColour=TFT_BLACK, .backText="",.surveyMap=false, .swapBytes=false, .mapLongitudeLeft = 1.263733, .mapLongitudeRight = 1.278033, .mapLatitudeBottom = 51.06265},

  [13] = { .mapData = lily_all_other_areas_All, .label="All", .backColour=TFT_BLACK, .backText="",
  .surveyMap=false, .swapBytes=false, .mapLongitudeLeft = 1.256483, .mapLongitudeRight = 1.285283,
  .mapLatitudeBottom = 51.059282},
};

const std::array<MapScreen_ex::pixel, MapScreen_T4::s_registrationPixelsSize> MapScreen_T4::s_registrationPixels
{{
[0]=  {  .x=o,     .y=o,     .colour=0xFF00},
[1]=  {  .x=hX_t3-o,  .y=o,     .colour=0xFF00},
[2]=  {  .x=o,     .y=hY_t3-o,  .colour=0xFF00},
[3]=  {  .x=hX_t3-o,  .y=hY_t3-o,  .colour=0xFF00},
  
[4]=  {  .x=hX_t3+o,  .y=o,     .colour=0xFFFF},
[5]=  {  .x=mX_t3-o,  .y=o,     .colour=0xFFFF},
[6]=  {  .x=hX_t3+o,  .y=hY_t3-o,  .colour=0xFFFF},
[7]=  {  .x=mX_t3-o,  .y=hY_t3-o,  .colour=0xFFFF},

[8]=  {  .x=o,     .y=hY_t3+o,  .colour=0x00FF},
[9]=  {  .x=hX_t3-o,  .y=hY_t3+o,  .colour=0x00FF},
[10]= {  .x=o,     .y=mY_t3-o,  .colour=0x00FF},
[11]= {  .x=hX_t3-o,  .y=mY_t3-o,  0x00FF},

[12]= {  .x=hX_t3+o,  .y=hY_t3+o,  .colour=0x0000},
[13]= {  .x=mX_t3-o,  .y=hY_t3+o,  .colour=0x0000},
[14]= {  .x=hX_t3+o,  .y=mY_t3-o,  .colour=0x0000},
[15]= {  .x=mX_t3-o,  .y=mY_t3-o,  .colour=0x0000}
}};     // How weird this is an older syntax from C++11 which requires an extra open and close brace.

const MapScreen_ex::MapScreenAttr MapScreen_T4::s_mapT4Attr = 
{
  .diverSpriteColour = TFT_BLUE,
  .diverSpriteRadius = 15,

  .headingIndicatorColour = TFT_RED,
  .headingIndicatorRadius = 8,
  .headingIndicatorOffsetX = 15,
  .headingIndicatorOffsetY = 0,

  .diverHeadingColour = TFT_BLUE,
  .diverHeadingLinePixelLength = 100,

  .featureSpriteColour = TFT_MAGENTA,
  .featureSpriteRadius = 5,

  .targetSpriteColour = TFT_RED,
  .lastTargetSpriteColour = TFT_BLUE,

  .nearestExitLineColour = TFT_DARKGREEN,
  .nearestExitLinePixelLength = 135,

  .targetLineColour = TFT_RED,
  .targetLinePixelLength = 175,

  .breadCrumbColour = TFT_RED,
  .breadCrumbWidth = 21,
  .breadCrumbDropFixCount = 5,    // record location every 5 fixes.

  .pinBackColour = TFT_DARKGREEN,
  .pinForeColour = TFT_ORANGE,
  .pinWidth = 30,

  .useSpriteForFeatures = false,

  .traceColour = TFT_DARKGREY,
  .tracePointSize = 3
};

MapScreen_ex::pixel MapScreen_T4::getRegistrationMarkLocation(int index) 
{ 
    if (index < s_registrationPixelsSize)
        return s_registrationPixels[index];
    else 
        return pixel(-1,-1);
}

/*
// _featureToMaps NOT USED?
void MapScreen_T4::initFeatureToMapsLookup()
{
  if (_location == e_wraysbury_location)
  {
    for (int i=0; i<WraysburyWaypoints::getWaypointsCount(); i++)                    // MBJ REFACTOR  - needs range and enumerate in C++20
    {
      sForFeature(WraysburyWaypoints::waypoints[i],_featureToMaps[i]);     // index i used here
    }
  }
}

// _featureToMaps NOT USED?
void MapScreen_T4::initMapsForFeature(const NavigationWaypoint& waypoint, geoRef& ref)
{
  if (_location == e_wraysbury_location)
  {
    int refIndex = 0;  

    pixel p;
    
    for (uint8_t i = getFirstDetailMapIndex(); i < getEndDetailMaps(); i++)    // MBJ REFACTOR  - needs range and enumerate in C++20 (with break at getEndDetailMaps())
    {
      p = convertGeoToPixelDouble(waypoint._lat, waypoint._long, s_maps[i]);
      if (p.x >= 0 && p.x < getTFTWidth() && p.y >=0 && p.y < getTFTHeight())
      {
        ref.geoMaps[refIndex++] = i;    // index i used here
      }
      else
      {
        ref.geoMaps[refIndex++] = -1;
      }
    }
  }
}
*/

MapScreen_T4::MapScreen_T4(TFT_eSPI& tft, LilyGo_AMOLED& lilygoT3) : MapScreen_ex(tft,s_mapT4Attr),_amoled(lilygoT3)
{
  _useDebugScreens = false;

  _scratchPadSprite = std::make_unique<TFT_eSprite>(&tft);  
  _scratchPadSprite->createSprite(getTFTWidth(),getTFTHeight());
  _scratchPadSprite->loadFont(NotoSansBold36);

  //sprintf(_debugString,"loadedfont"); fillScreen(TFT_BROWN); delay(1000);
  _locationInitialised = false;
  _location = e_wraysbury_location;

   initMapScreen();

 // initFeatureToMapsLookup();


  //sprintf(_debugString,"initmapscreen"); fillScreen(TFT_BROWN); delay(1000);
}

void MapScreen_T4::initFirstAndEndWaypointsIndices()
{
  _firstWaypointIndex = 0;
  _endWaypointsIndex = WraysburyWaypoints::getWaypointsCount();
/*
  switch (_location)
  {
    case e_vobster_location:
      _firstWaypointIndex = WraysburyWaypoints::getStartIndexVobster(); 
      _endWaypointsIndex = WraysburyWaypoints::getEndWaypointIndexVobster();
      break;
    case e_wraysbury_location:
      _firstWaypointIndex = WraysburyWaypoints::getStartIndexWraysbury();
      _endWaypointsIndex = WraysburyWaypoints::getEndWaypointIndexWraysbury();
      break;
    case e_home_location:
      _firstWaypointIndex = WraysburyWaypoints::getStartIndexHome(); 
      _endWaypointsIndex = WraysburyWaypoints::getEndWaypointIndexHome();
      break;
    case e_other_location:
      _firstWaypointIndex = WraysburyWaypoints::getStartIndexOtherAreas(); 
      _endWaypointsIndex = WraysburyWaypoints::getEndWaypointIndexOtherAreas();
      break;
    case e_uninitialised_location:
    default:
      _firstWaypointIndex = WraysburyWaypoints::getStartIndexHome(); 
      _endWaypointsIndex = WraysburyWaypoints::getEndWaypointIndexHome();
      break;
  }
*/
}

// de-dupe later
const double uninitialisedLatitude = 0.0;
const double uninitialisedLongitude = 0.0;

void MapScreen_T4::setLocationLatLong(double lat, double lng)
{
  bool overrideToVobster = false;
  
  USB_SERIAL.println("Start: setLocationLatLong");

  const MapScreen_ex::geo_map* m = nullptr;

  locations previousLocation = _location;

  if (lat == uninitialisedLatitude && lng == uninitialisedLongitude)
  {
    USB_SERIAL.println("Matched on Uninitialised Location");
    _location = e_uninitialised_location;
  }
  else
  {
    const double fixedLatitudeUpperBoundDelta = 0.1; // arbitrary to make a bounding box.

    m = s_maps+_allLake_WraysburyMapIndex;
    if (overrideToVobster)
    {
      USB_SERIAL.println("Overriden Location to Vobster");
      _location = e_vobster_location;
    }
    else
    {
      if (lng > m->mapLongitudeLeft && lng < m->mapLongitudeRight &&
          lat > m->mapLatitudeBottom && lat < m->mapLatitudeBottom+fixedLatitudeUpperBoundDelta)
      {
            USB_SERIAL.println("Matched On Wraysbury Location");
          _location = e_wraysbury_location;
      }
      else
      {
        m = s_maps+_homeAllMapIndex;    // test for home location

        if (lng > m->mapLongitudeLeft && lng < m->mapLongitudeRight &&
              lat > m->mapLatitudeBottom && lat < m->mapLatitudeBottom+fixedLatitudeUpperBoundDelta)
        {
          USB_SERIAL.println("Matched On Home Location");
          _location = e_home_location;
        }
        else
        {
          USB_SERIAL.printf("Lat: %f Long: %f,  home-bounds: %f, %f, %f\n", lat, lng, m->mapLongitudeLeft, m->mapLongitudeRight, m->mapLatitudeBottom);

          m = s_maps+_vobsterAllLakeMapIndex; // test for vobster location

          if (lng > m->mapLongitudeLeft && lng < m->mapLongitudeRight &&
              lat > m->mapLatitudeBottom && lat < m->mapLatitudeBottom+fixedLatitudeUpperBoundDelta)
          {
            USB_SERIAL.println("Matched On Vobster Location");
            _location = e_vobster_location;
          }
          else
          {
            USB_SERIAL.println("Matched On Other Location");
            _location = e_other_location;   // ********* out of range of all *********
          }
        }
      }
    }
  }

  if (previousLocation != _location)
  {
    USB_SERIAL.printf("Location change triggers clearMap() %s to %s\n",getLocationName(previousLocation),getLocationName(_location));
    const bool clearToBlack=false;
    clearMap(clearToBlack);  // force a map redraw based on new location.

  }

  initFirstAndEndWaypointsIndices();
  
  initExitWaypoints();

//  //sprintf(_debugString,"exitwaycount %i",_exitWaypointCount); fillScreen(TFT_BROWN); delay(1000);

  USB_SERIAL.println("End: setLocationLatLong");
}

void MapScreen_T4::drawMapScaleToSprite(TFT_eSprite& sprite, const geo_map& featureMap)
{
  pixel right_anchor(getTFTWidth() - 30,70);

  int markLength = 10; // pixels
  int yOffsetLabel = 10; // pixels off anchor

  int scaleColour = TFT_VIOLET;
  int fontSize = 1;

  int distanceToShow = 0;
  int pixelsForDistance = 0;

  if (isAllLakeShown())
  {
    switch (_location)
    {
      case e_vobster_location:
        distanceToShow = 100;
        pixelsForDistance = 108; // needs correcting
        break;
      case e_home_location:
        distanceToShow = 100;
        pixelsForDistance = 108; // needs correcting
        break;
      case e_wraysbury_location:
        distanceToShow = 100;
        pixelsForDistance = 108; // worth checking
        break;
      case e_other_location:  // assuming 2km width 'all' map
      default:
        distanceToShow = 300;
        pixelsForDistance = 90;
        break;
    }
  }
  else
  {
    if (_zoom == 1)
      distanceToShow = 30;
    else if (_zoom == 2)
      distanceToShow = 20;
    else if (_zoom == 3)
      distanceToShow = 20;
    else if (_zoom == 4)
      distanceToShow = 10;

    pixelsForDistance = getPixelsFor10metres() * (distanceToShow / 10) * _zoom;
  }

  char distanceLabel[5];
  snprintf(distanceLabel,sizeof(distanceLabel),"%dm",distanceToShow);

  sprite.drawFastHLine(right_anchor.x - pixelsForDistance, right_anchor.y, pixelsForDistance,scaleColour);  // horiz scale line
  sprite.drawFastHLine(right_anchor.x - pixelsForDistance, right_anchor.y+1, pixelsForDistance,scaleColour);  // horiz scale line
  sprite.drawFastHLine(right_anchor.x - pixelsForDistance, right_anchor.y+2, pixelsForDistance,scaleColour);  // horiz scale line

  sprite.drawFastVLine(right_anchor.x - pixelsForDistance, right_anchor.y - markLength, markLength, scaleColour); // left tick
  sprite.drawFastVLine(right_anchor.x - pixelsForDistance+1, right_anchor.y - markLength, markLength, scaleColour); // left tick
  sprite.drawFastVLine(right_anchor.x - pixelsForDistance+2, right_anchor.y - markLength, markLength, scaleColour); // left tick
  
  sprite.drawFastVLine(right_anchor.x, right_anchor.y - markLength, markLength, scaleColour);    // right tick
  sprite.drawFastVLine(right_anchor.x-1, right_anchor.y - markLength, markLength, scaleColour);    // right tick
  sprite.drawFastVLine(right_anchor.x-2, right_anchor.y - markLength, markLength, scaleColour);    // right tick

  sprite.setTextColor(scaleColour);
  sprite.drawCentreString(distanceLabel,right_anchor.x - pixelsForDistance / 2, right_anchor.y + yOffsetLabel,1);    // scale label
}

void MapScreen_T4::testAndDisplayScale()
{
  getCompositeSprite().fillSprite(TFT_RED);
  getCompositeSprite().setCursor(0,30);

  // x1 zoom map
  measureScale(10,_SMap);  // 29 pixels
  measureScale(20,_SMap);  // 58 pixels
  measureScale(100,_SMap); // 290 pixels

  // all lake map
  measureScale(10,_allLakeMap);   // 10 pixels
  measureScale(20,_allLakeMap);   // 21 pixels
  measureScale(100,_allLakeMap);  // 108 pixels

  delay(30000);
}

void MapScreen_T4::measureScale(double requiredDistance, const MapScreen_ex::geo_map* featureMap)
{
  getCompositeSprite().printf("Pixels for %.0f m ",requiredDistance);
  copyCompositeSpriteToDisplay();

  double startLatitude = 51.4601315714286;
  double startLongitude = -0.547417857142857;
  double diverLatitude = startLatitude;
  double diverLongitude = startLongitude;

  MapScreen_ex::pixel startPixel = convertGeoToPixelDouble(diverLatitude, diverLongitude, *featureMap);
  MapScreen_ex::pixel endPixel = startPixel;

  double distance = 0.0;

  while (distance < requiredDistance)
  {
    diverLongitude += 0.0000001;

    distance = distanceBetween(startLatitude, startLongitude, diverLatitude, diverLongitude);
  }

  endPixel = convertGeoToPixelDouble(diverLatitude, diverLongitude, *featureMap);

  getCompositeSprite().printf("= %hu\n",endPixel.x-startPixel.x);
  copyCompositeSpriteToDisplay();
}

void MapScreen_T4::initMapScreen()
{
  MapScreen_ex::initMapScreen();

  getCompositeSprite().loadFont(NotoSansBold36);

  if (&getBaseMapSprite() != &getCompositeSprite())
    getBaseMapSprite().loadFont(Final_Frontier_28);
}

bool MapScreen_T4::useBaseMapCache() const
{
    // base map cache is used for oceanic because the much larger screen
    // takes much longer to update than with tiger on the M5. The M5 doesn't
    // need the map cache and this helps as tiger is otherwise very short / too short of memory now.
    // Frame rate slows by at least factor of 2 if map cache not used with Oceanic.
    return true;
}

int MapScreen_T4::getFirstDetailMapIndex()
{
  switch (_location)
  {
    case e_vobster_location:
      return _vobsterCentreMapIndex;
    case e_home_location:
      return _homeCentreMapIndex;
    case e_wraysbury_location:
      return _N_WraysburyMapIndex;
    case e_other_location:
    default:
      return _allOtherAreasCentreMapIndex;
  }
}

int MapScreen_T4::getEndDetailMaps()
{
  switch (_location)
  {
    case e_vobster_location:
      return _vobsterAllLakeMapIndex;
    case e_home_location:
      return _homeAllMapIndex;
    case e_wraysbury_location:
      return _allLake_WraysburyMapIndex;
    case e_other_location:
    default:
      return _allOtherAreasAllMapIndex;
  }
}

int MapScreen_T4::getAllMapIndex()
{
  return getEndDetailMaps();
}

const MapScreen_ex::geo_map* MapScreen_T4::getMaps()
{
  return s_maps;
}

void MapScreen_T4::copyFullScreenSpriteToDisplay(TFT_eSprite& sprite)
{
    _amoled.pushColors(0,0,getTFTWidth(),getTFTHeight(),reinterpret_cast<uint16_t*>(sprite.getPointer()));
}

void MapScreen_T4::fillScreen(int colour)
{
  _scratchPadSprite->fillSprite(colour);
  if (_debugString[0] != '\0')
  {
    _scratchPadSprite->setCursor(0,20);
    _scratchPadSprite->setTextSize(2);
    _scratchPadSprite->setTextColor(TFT_WHITE);
    _scratchPadSprite->printToSprite(_debugString);
    _debugString[0] = '\0';
  }
  copyFullScreenSpriteToDisplay(*_scratchPadSprite);
}

// This needs customising for the T4 maps. Writes text to the canoe/sub zoomed in zones
void MapScreen_T4::writeMapTitleToSprite(TFT_eSprite& sprite, const MapScreen_ex::geo_map& map)
{
  sprite.setCursor(0,20);
  sprite.setTextSize(3);
  sprite.setTextColor(TFT_DARKGREY);
  double scaledDistance = _targetDistance;
  char distanceUnitPrefix = ' ';
  if (_targetDistance >= 1000)
  {
    distanceUnitPrefix = 'k';
    scaledDistance = _targetDistance / 1000.0;
  }

  const char unknownWaypoint[] = "??? Unknown";
  
  const char* label = (_targetWaypointIndex != -1 ? WraysburyWaypoints::waypoints[_targetWaypointIndex]._label : unknownWaypoint);

  const char* targetLabelMinusCode = strstr(label," ");

  if (targetLabelMinusCode)
    targetLabelMinusCode++;
  else
  {
    targetLabelMinusCode=label;
  }
- 
  sprite.printf("%.0f%cm to %s",scaledDistance, distanceUnitPrefix, targetLabelMinusCode);
  
  sprite.setCursor(555,20);

  char x = (isAllLakeShown() ? ' ' : 'x');
  char zoom = (isAllLakeShown() ? ' ' :  '0' + _zoom);

  sprite.printf("%c%c",x, zoom);

  sprite.setCursor(0,375);

  const char* nearestLabelMinusCode = strstr(WraysburyWaypoints::waypoints[_nearestFeatureIndex]._label," ");

  if (nearestLabelMinusCode)
    nearestLabelMinusCode++;
  else
  {
    nearestLabelMinusCode=WraysburyWaypoints::waypoints[_nearestFeatureIndex]._label;
  }

  if (_nearestFeatureDistance < 5)
  {
    sprite.printf("%.0fm At %s",_depth, nearestLabelMinusCode);
  }
  else if (_nearestFeatureDistance < 12)
  {
    sprite.printf("%.0fm Near to %s (%.0f m)",_depth, nearestLabelMinusCode, _nearestFeatureDistance);
  }

  sprite.setCursor(450, 417);

  if(_temperature != -1.0 && _humidity != -1.0)
  {
    sprite.setTextColor(TFT_NAVY);
    sprite.printf("%.0fC ",_temperature);

    if (_humidity > 85)
        sprite.setTextColor(TFT_RED);
    else if (_humidity > 80)
        sprite.setTextColor(TFT_ORANGE);
    else if (_humidity > 75)
        sprite.setTextColor(TFT_GREENYELLOW);
    else
        sprite.setTextColor(TFT_DARKGREEN);

    sprite.printf("%.0f%%",_humidity);
  }
  else
  {
    sprite.setTextColor(TFT_RED);
    sprite.printf("ERROR");
  }

  sprite.setCursor(260,417);
  
  if (_lidarDistance >= 0.05)
  {   
    sprite.setTextColor(TFT_MAGENTA);
    sprite.printf("%.1f m",_lidarDistance);
  }
  else if (_lidarDistance == -2)
  {
    sprite.setTextColor(TFT_DARKGREY);
    sprite.printf("%.1f m",_prevLidarDistance);
  }
  else if (_lidarDistance == -0.5)
  {
    sprite.setTextColor(TFT_RED);
    sprite.printf("NO OBJ");
  }
  else
  {
    // nothing to print
  }
}

// This needs customising for the T4 maps. Currently switches when within 30 pixels of screen edge.
const MapScreen_ex::geo_map* MapScreen_T4::getNextMapByPixelLocation(MapScreen_ex::pixel loc, const MapScreen_ex::geo_map* thisMap)
{
  //sprintf(_debugString,"Enter getNextMapByPixelLocation"); fillScreen(TFT_BLACK); delay(1000);

  const MapScreen_ex::geo_map* nextMap = thisMap;

  USB_SERIAL.printf("Location: %s\n",getLocationName(_location));

  
  USB_SERIAL.println("getNextMapByPixelLocation: not ALL Map");

  if (_location == e_wraysbury_location)
  {
    if ((thisMap == _canoeZoneMap || thisMap == _subZoneMap) && isPixelOutsideScreenExtent(loc))
    {
      nextMap = (thisMap == _canoeZoneMap ? _NMap : _SWMap);
      _zoom = _prevZoom;
    }
    else if (thisMap == _NMap)   // go right from 0 to 1
    {
      if (isPixelInCanoeZone(loc, *thisMap))
      {
        _prevZoom=_zoom;
        _zoom = 1;
        nextMap = _canoeZoneMap;
      }
      else if (isPixelInSubZone(loc, *thisMap))
      {
        _prevZoom=_zoom;
        _zoom = 1;
        nextMap = _subZoneMap;
      }
      else if (loc.y >= 370)
      {
        nextMap=_WMap;
      }
    }
    else if (thisMap == _WMap)
    { 
      if (isPixelInCanoeZone(loc, *thisMap))
      {
        _prevZoom=_zoom;
        _zoom = 1;
        nextMap = _canoeZoneMap;
      }
      else if (isPixelInSubZone(loc, *thisMap))
      {
        _prevZoom=_zoom;
        _zoom = 1;
        nextMap = _subZoneMap;
      }
      else if (loc.x >= 570 || loc.y >= 420 )
      {
        nextMap=_SWMap;
      }
      else if (loc.y <= 30)
      {
        nextMap=_NMap;
      }
    }
    else if (thisMap == _SWMap)
    {
      if (loc.x >= 570 || loc.y >= 420)
        nextMap=_SMap;
      else if (loc.x <= 1 || loc.y <= 30)
        nextMap=_WMap;          // go left from 2 to 1
    }
    else if (thisMap == _SMap)
    {
      if  (loc.x <= 30 || loc.y <= 30) // go left from 3 to 2
        nextMap = _SWMap;
      else if (loc.x >= 570 || loc.y >= 420)
        nextMap = _SEMap;
    }
    else if (thisMap == _SEMap)
    {
      if  (loc.x <= 30 || loc.y <= 30) // go left from 3 to 2
        nextMap = _SMap;
  //    else if (loc.x >= 570 || loc.y >= 420)
  //      nextMap = _SEMap;
    }
  }
  else
  {
    if (_location == e_home_location)
    {
      nextMap = s_maps+getFirstDetailMapIndex();
    }
    else if (_location == e_vobster_location)
    {
      nextMap = s_maps+getFirstDetailMapIndex();
    }
    else if (_location == e_other_location)
    {
      nextMap = s_maps+getFirstDetailMapIndex();
    }
    else
    {
      nextMap == s_maps+getAllMapIndex();
    }
  }

  //sprintf(_debugString,"nextMap = %i", nextMap-s_maps); fillScreen(TFT_BROWN); delay(1000);

  return nextMap;
}

// MBJ RECALCULATE pixel bounding box for canoe FOR T4 DISPLAY
// This is the M5 canoe bounding box - needs updating for T4
// BOUNDING BOX FOR CANOE M5: TOP-LEFT (62, 51) BOT-RIGHT (79, 71) 
const std::array<MapScreen_ex::MapScreen_ex::BoundingBox, 1> MapScreen_T4::boundingBoxesCanoe = {{{{62,51},{79,71},{*MapScreen_T4::_NMap}}}};
bool MapScreen_T4::isPixelInCanoeZone(const MapScreen_ex::pixel loc, const MapScreen_ex::geo_map& thisMap) const
{
  return false; // temp - remove when new bounding box pixels are coded above

  for (auto& box : boundingBoxesCanoe)
  {
    if (box.withinBox(loc, thisMap))
      return true;
  }

  return false;
}

// MBJ RECALCULATE pixel bounding box for sub FOR T4 DISPLAY
// BOUNDING BOX FOR SUB M5 North Map: TOP-LEFT (48, 168) BOT-RIGHT (65, 191)
// BOUNDING BOX FOR SUB M5 Cafe Jetty Map: TOP-LEFT (12, 53) BOT-RIGHT (31, 72)
const std::array<MapScreen_ex::MapScreen_ex::BoundingBox, 2> MapScreen_T4::boundingBoxesSub = { {
                  {{48,168},{65,191},{*MapScreen_T4::_NMap}},
                  {{12,53},{31,72},{*MapScreen_T4::_NMap/*_cafeJettyMap*/}}
                  } };

bool MapScreen_T4::isPixelInSubZone(const MapScreen_ex::pixel loc, const geo_map& thisMap) const
{
  return false;  // temp - remove when new bounding box pixels are coded above

  for (auto& box : boundingBoxesSub)
  {
    if (box.withinBox(loc, thisMap))
      return true;
  }

  return false;
}
