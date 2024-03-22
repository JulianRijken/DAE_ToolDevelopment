class Sprite{

public: 
    void Update(float dt)
    {
        std::cout << "Sprite Update" << std::endl;
    }

    void Draw() const
    {
        std::cout <<"Sprite Draw" <<std::endl;
    }
};