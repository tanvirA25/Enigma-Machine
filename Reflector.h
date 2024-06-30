#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
public:
    static Reflector& Instance();
    const unsigned char reflect(const unsigned char c);

private:
    Reflector();
    Reflector(const Reflector&) = delete;
    Reflector& operator=(const Reflector&) = delete;
};

#endif // REFLECTOR_H

