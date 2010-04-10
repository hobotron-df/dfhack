#ifndef CL_MOD_BUILDINGS
#define CL_MOD_BUILDINGS
/*
* Buildings - also includes zones and stockpiles
*/
#include "Export.h"
namespace DFHack
{
    struct t_building
    {
        uint32_t origin;
        uint32_t vtable;
        
        uint32_t x1;
        uint32_t y1;
        
        uint32_t x2;
        uint32_t y2;
        
        uint32_t z;
        
        t_matglossPair material;
        
        uint32_t type;
        // FIXME: not complete, we need building presence bitmaps for stuff like farm plots and stockpiles, orientation (N,E,S,W) and state (open/closed)
    };
    
    struct APIPrivate;
    class DFHACK_EXPORT Buildings
    {
        public:
        Buildings(APIPrivate * d);
        ~Buildings();
        bool Start(uint32_t & numBuildings);
        bool Read (const uint32_t index, t_building & building);
        bool Finish();
        
        private:
        struct Private;
        Private *d;
    };
}
#endif