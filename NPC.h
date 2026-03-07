#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"
`
class NPC : public SpatialEntity {
public:
    NPC(float start_x, float start_y);
    
    void update(float delta_time) override;
    void on_event(Event& event) override;
    char get_symbol() const override { return 'N'; }
};

#endif
