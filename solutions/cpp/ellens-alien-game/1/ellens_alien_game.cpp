namespace targets {
// TODO: Insert the code for the alien class here
class Alien {
    public:
    int x_coordinate, y_coordinate;
    
    Alien(int x, int y) : x_coordinate{x}, y_coordinate{y}, health{3} {};

    int get_health() {
        return health;
    }

    bool hit() {
        if (health > 0)
            --health;
        return true;
    }

    bool is_alive() {
        return health > 0;
        
    }

    bool teleport(int new_x, int new_y) {
        x_coordinate = new_x;
        y_coordinate = new_y;
        return true;
    }

    bool collision_detection(Alien other) {
        return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;
    }
    
    private:
    int health;
};

}  // namespace targets