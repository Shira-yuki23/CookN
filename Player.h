#ifndef PLAYER_H
#define PLAYER_H

#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
    Player(float startX, float startY);

    void update(float delta_time) override;

    void draw(float alpha) override;

    void on_event(const Event& event) override;

    char get_symbol() const override { return 'P'; }
};

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
#endif
<<<<<<< HEAD
=======


>>>>>>> 4569e1523a852dfdc9dd00d7f7a793d0362ce5d6
=======
#endif

>>>>>>> origin/main
>>>>>>> arshiyahera-patch-1
