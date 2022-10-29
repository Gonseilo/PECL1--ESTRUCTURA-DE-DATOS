#ifndef PILAS_H
#define PILAS_H
#define N3 5

class Pilas{
    public:
        Pilas();
        int top;
        void push(int, int[]);
        void pop(int[]);
        void PrintPila(int[]);
        virtual ~Pilas();

    protected:

    private:
};

#endif // PILAS_H
