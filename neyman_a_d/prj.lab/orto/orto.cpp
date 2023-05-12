#include <iostream>

namespace geo2d {
    namespace orto {

        class Quad {
        private:
            int ax = 0;
            int ay = 0; //координаты верхней левой точки
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0; //сторона из нижней левой точки в верхнюю левую
        protected:
            int x = 0;
            int y = 0;
        public:
            Quad() {};

            Quad(int _x, int _y) {
                x = _x;
                y = _y;
            }
            Quad(int _x, int _y, int _ax, int _ay, int _a, int _b, int _c, int _d){
                x = _x;
                y = _y;
                ax = _ax;
                ay = _ay;
                a = _a;
                b = _b;
                c = _c;
                d = _d;
            }

            void Scale(int _ax, int _ay, int _a, int _b, int _c, int _d) {
                ax = _ax;
                ay = _ay;
                a = _a;
                b = _b;
                c = _c;
                d = _d;
            }

            geo2d::orto::Quad Union(geo2d::orto::Quad &then){
                int newax = ((then.ax > ax) ? ax : then.ax);
                int neway = ((then.ay > ay) ? ay : then.ay);

                int newbx = (((then.ax + then.a) > (ax + a)) ? (then.ax + then.a) : (ax+ a));
                int newby = (((then.ay + then.b) > (ay + b)) ? (then.ay + then.b) : (ay + b));
            }
        };

        class Rect : public Quad {
        private:
            int ax = 0;
            int ay = 0;
            int a = 0;
            int b = 0;
        public:
            Rect(){
                x = 0;
                y = 0;
                a = 0;
                b = 0;
            }

            Rect(int _x, int _y){
                x = _x;
                y = _y;
                a = 0;
                b = 0;
            }

            Rect(int _x, int _y, int _a, int _b){
                x = _x;
                y = _y;
                a = _a;
                b = _b;
            }

            void Scale(int _a, int _b){
                a = _a;
                b = _b;
            }


        };

        class Square : public Quad {
        private:
            int a = 0;
        public:
            Square() {
                x = 0;
                y = 0;
                a = 0;
            }

            Square(int _x, int _y) {
                x = _x;
                y = _y;
                a = 0;
            };

            Square(int _x, int _y, int _a) {
                x = _x;
                y = _y;
                a = _a;
            };

            void Scale(int _a) {
                a = _a;
            }
        };

    }
}

int main() {
    geo2d::orto::Quad a;
    geo2d::orto::Rect b;
    geo2d::orto::Square c;
}
