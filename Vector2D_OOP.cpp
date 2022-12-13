#include <iostream>
#include <tgmath.h>

using std::cout, std::endl;

class Vector 
{
	
	public:
	//Klasa bez implementacji
	virtual double getNorm() = 0;
//Nie moze byc uzyty do utworzenia bezposrednio obiektu ale w overriderzy tworzeniu
// hierarchii obiektow bedzie uzyty
	Vector()
	{
		cout<<"Vector constructor"<<endl;
	}
};


class Vector2D : public Vector
{
	protected:
	int x,y;

	public:
	//Domyslny konstruktor bez listy inic dzieki temu w klasie 
	//pochodnej Vector3D nie musimy korzystac z konstruktora z lista inic
	Vector2D()=default;

	Vector2D(int x, int y) : x(x) , y(y)
	{
		printf("Construction of vector [%d, %d]\n",x,y);
	}
	double getNorm() override 
	{
		cout<<"Norm of Vector2D"<<endl;
		return sqrt(x*x + y*y);
	}
	virtual double getSum()
	{
		cout<<"Sum of Vector2D"<<endl;
		return(x + y);
	}
//albo protected go zrobic
//	protected:
	virtual	~Vector2D()
	{
		cout<<"Destruction of Vector2D"<<endl;
	}
};
class Vector3D : public Vector2D
{
	protected:
	int z;
	public:
	//konstruktor z lista inicjalizacyjna musi zostac wywolany
	//konstruktor klasy bazowej
	Vector3D(int xx, int yy, int z) : z(z)
	{
		x=xx;
		y=yy;
		printf("Construction of vector [%d, %d, %d]\n",x,y,z);
	}
	double getNorm()
	{
		cout<<"Norm of Vector3D"<<endl;
		return sqrt(x*x + y*y + z*z);
	}
	double getSum()
	{
		cout<<"Sum of Vector3D"<<endl;
		return(x + y + z);
	}
	~Vector3D()
	{
		cout<<"Destruction of Vector3D"<<endl;
	}

	

};

void foo(Vector2D v)
{
	v.getNorm();
}

void voo(Vector2D &v)
{
	v.getSum();
}

int main()
{
//	Vector2D v1(1,3);
//	Vector3D v2(1,3,5);
//	v2.getNorm();
//	v2.Vector2D::getNorm();
//	foo(v2);
//parametr v w funkcji voo jest referencja na wektor 3D mimo ze funkcja bierze z 2D
//	voo(v2);
//Abstrakcyjna klasa z wirtualna metoda nie mozna stworzyc jej obiektu
//	Vector v;
//	wskaznik typu 2D na wektor typu 3D
//	polimorficzna manipulacja na obiektach musimy zadbac
//	aby destruktor 2D wirtualny
//	albo destruktor moze byc typu proteced
	Vector2D* V= new Vector3D(1,1,1);
	delete V;
}
