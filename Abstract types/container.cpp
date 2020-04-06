class Container {
    public:
        virtual double& operator[](int s) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
};
