#ifndef MAPSCREEN_T4_H
#define MAPSCREEN_T4_H

#include <MapScreen_ex.h>

#include "NavigationWaypoints.h"

class LilyGo_AMOLED;

class MapScreen_T4 : public MapScreen_ex
{
    private:
        static constexpr int s_registrationPixelsSize = 16;
        static const std::array<MapScreen_ex::pixel, s_registrationPixelsSize> s_registrationPixels;

        static constexpr int16_t mX_t3 = 600,  hX_t3 = 300;
        static constexpr int16_t mY_t3 = 450,  hY_t3 = 225;
        static constexpr int16_t o = 30;

        static const int s_allLakeMapIndex = 5;
        static const int s_canoeMapIndex = 6;
        static const int s_subMapIndex = 7;
        static const int s_initialZoom = 1;

        float _temperature = 0.0;
        float _humidity = 0.0;
        float _lidarDistance = 0.0;
        float _prevLidarDistance = 0.0;

        LilyGo_AMOLED& _amoled;
    
        std::unique_ptr<TFT_eSprite> _scratchPadSprite;
        
        virtual void initMapScreen() override;
        virtual bool useBaseMapCache() const override;

        virtual int getFirstDetailMapIndex() override;
        virtual int getEndDetailMaps() override;
        virtual int getAllMapIndex() override;
        virtual const MapScreen_ex::geo_map* getMaps() override;

        virtual const MapScreen_ex::geo_map* getNextMapByPixelLocation(MapScreen_ex::pixel loc, const MapScreen_ex::geo_map* thisMap) override;

        static const MapScreen_ex::geo_map s_maps[];

        static constexpr const MapScreen_ex::geo_map* _NMap=s_maps;          static const uint8_t _N_WraysburyMapIndex = 0;
        static constexpr const MapScreen_ex::geo_map* _WMap=s_maps+1;        static const uint8_t _WMapIndex = 1;
        static constexpr const MapScreen_ex::geo_map* _SWMap=s_maps+2;       static const uint8_t _SWMapIndex = 2;
        static constexpr const MapScreen_ex::geo_map* _SMap=s_maps+3;        static const uint8_t _SMapIndex = 3;
        static constexpr const MapScreen_ex::geo_map* _SEMap=s_maps+4;       static const uint8_t _SEMapIndex = 4;
        static constexpr const MapScreen_ex::geo_map* _allLakeMap=s_maps+5;  static const uint8_t _allLake_WraysburyMapIndex = 5;
        static constexpr const MapScreen_ex::geo_map* _canoeZoneMap=s_maps+6;static const uint8_t _canoeZoneMapIndex = 6;
        static constexpr const MapScreen_ex::geo_map* _subZoneMap=s_maps+7;  static const uint8_t _subZoneMapIndex = 7;
        static constexpr const MapScreen_ex::geo_map* _homeCentreMap=s_maps+8;  static const uint8_t _homeCentreMapIndex = 8;
        static constexpr const MapScreen_ex::geo_map* _homeAllMap=s_maps+9;  static const uint8_t _homeAllMapIndex = 9;
        static constexpr const MapScreen_ex::geo_map* _vobsterCentreMap=s_maps+10;  static const uint8_t _vobsterCentreMapIndex = 10;
        static constexpr const MapScreen_ex::geo_map* _vobsterAllLakeMap=s_maps+11;  static const uint8_t _vobsterAllLakeMapIndex = 11;
        static constexpr const MapScreen_ex::geo_map* _allOtherAreasCentreMap=s_maps+12;  static const uint8_t _allOtherAreasCentreMapIndex = 12;
        static constexpr const MapScreen_ex::geo_map* _allOtherAreasAllMap=s_maps+13;  static const uint8_t _allOtherAreasAllMapIndex = 13;

        static const std::array<MapScreen_ex::MapScreen_ex::BoundingBox, 1> boundingBoxesCanoe;
        static const std::array<MapScreen_ex::MapScreen_ex::BoundingBox, 2> boundingBoxesSub;

/*
        static const int maxFeatures = 255;
        std::array<MapScreen_ex::geoRef, maxFeatures>    _featureToMaps;
        void initFeatureToMapsLookup();
        void initMapsForFeature(const NavigationWaypoint& waypoint, MapScreen_ex::geoRef& ref);
*/
        static const MapScreenAttr s_mapT4Attr;

        const int wraysbury10metrePixelScale = 29;
        const int home10metrePixelScale = 29;
        const int vobster10metrePixelScale = 29;
        const int default10metrePixelScale = 29;

        // MBJMBJ this will need to change
        int getPixelsFor10metres() const
        {
            const bool wraysbury=true;
            return (wraysbury ? wraysbury10metrePixelScale : default10metrePixelScale);
        }

    protected:
        virtual void initFirstAndEndWaypointsIndices();

    public:
        MapScreen_T4(TFT_eSPI& tft, LilyGo_AMOLED& lilygoT3);

        virtual void setLocationLatLong(double lat, double lng);

        virtual MapScreen_ex::pixel getRegistrationMarkLocation(int index) override;

        virtual int getRegistrationMarkLocationsSize() override { return s_registrationPixelsSize; }

        virtual int16_t getTFTWidth() const override {return 600;}
        virtual int16_t getTFTHeight() const override {return 450; }

        virtual void fillScreen(int colour) override;
        virtual void copyFullScreenSpriteToDisplay(TFT_eSprite& sprite) override;
        virtual void writeMapTitleToSprite(TFT_eSprite& sprite, const MapScreen_ex::geo_map& map) override;

        virtual bool isPixelInCanoeZone(const MapScreen_ex::pixel loc, const MapScreen_ex::geo_map& thisMap) const override;
        virtual bool isPixelInSubZone(const MapScreen_ex::pixel loc, const MapScreen_ex::geo_map& thisMap) const override;

        virtual void drawMapScaleToSprite(TFT_eSprite& sprite, const geo_map& featureMap) override;
        
        void testAndDisplayScale();
        void measureScale(double requiredDistance, const MapScreen_ex::geo_map* featureMap);

        void setHumidityAndTemp(float goProCaseHumidity, float goProCaseTemperature)
        {
            _temperature = goProCaseTemperature;
            _humidity = goProCaseHumidity;
        }

        void setLidarDistance(float distance)
        { 
            if (distance > 0.2)
            {
                if (_lidarDistance > 0.2)
                    _prevLidarDistance = _lidarDistance;
                else
                    _prevLidarDistance = distance;
                                        
                _lidarDistance = distance;
            }
            else if (distance >= 0)
            {
               _lidarDistance = -2;
            }
            else
            {
                _lidarDistance = distance;
            }
        }
};

#endif

