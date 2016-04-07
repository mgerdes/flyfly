#ifndef GRAPHICS_BASIC_LINE_GEOMETRY_H
#define GRAPHICS_BASIC_LINE_GEOMETRY_H

class BasicLineGeometry : public Geometry {
    public:
        BasicLineGeometry() : Geometry(2) {
            addVertex(0.0, 0.0, 0.0);
            addVertex(0.0, 0.0, 1000.0);
        };
};

#endif

