class Remt {
public:
    float x;
    float y;
    float w;
    float h;
    Remt()
            : x(0)
            , y(0)
            , w(0)
            , h(0)
    {
    }
    Remt(float x1, float y1, float w1, float h1)
            : x(x1)
            , y(y1)
            , w(w1)
            , h(h1)
    {
    }
    Remt(const Remt& v);
    ~Remt();
};
Remt::Remt(const Remt& v)
        : x(v.x)
        , y(v.y)
        , w(v.w)
        , h(v.h)
{
}
Remt::~Remt() {}
