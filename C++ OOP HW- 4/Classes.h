#pragma once

class Computer
{
private:

	static size_t _staticID;
	size_t _ID;
	char* _Model;
	char* _Color;
	size_t _Year;
	char* _CPU; // Intel Core i7-8550U
	short _RAM;
	size_t _Space; // (Hard disc or SSD)

public:

	// Constructors.

	Computer();
	explicit Computer(const char* Model);
	Computer(const char* Model, const char* Color);
	Computer(const char* Model, const char* Color, const size_t Year);
	Computer(const char* Model, const char* Color, const size_t Year, const char* CPU);
	Computer(const char* Model, const char* Color, const size_t Year, const char* CPU, const short int RAM);
	Computer(const char* Model, const char* Color, const size_t Year, const char* CPU, const short int RAM, const size_t Space);
	Computer(const Computer& garage);
	Computer(Computer&& other);

	// Setter Methods.

	void Set_Id(const int sfId);
	void Set_Model(const char* sfModel);
	void Set_Color(const char* sfColor);
	void Set_Year(const size_t sfYear);
	void Set_Cpu(const char* sfCpu);
	void Set_Ram(const short int sfRam);
	void Set_Space(const size_t sfSpace);

	// Getter Methods.

	const size_t Get_StaticId()const;
	const size_t Get_Id()const;
	const char* Get_Model()const;
	const char* Get_Color()const;
	const size_t Get_Year()const;
	const char* Get_Cpu()const;
	const short int Get_Ram()const;
	const size_t Get_Space()const;

	// Methods. 

	Computer& operator=(const Computer& other);

	void Print()const;

	// Destructor.

	~Computer();

};


class CompStore
{
private:

	char* _Name;
	char* _Address;
	Computer** _Computers;
	size_t _Count;

public:

	// Constructors.

	CompStore();
	CompStore(const char* Name);
	CompStore(const char* Name, const char* Address);
	CompStore(const char* Name, const char* Address, Computer** Computers, size_t Count);
	CompStore(const CompStore& garage);
	CompStore(CompStore&& other);

	// Setter Methods.

	void Set_Name(const char* sfName);
	void Set_Address(const char* sfAddress);
	void Set_Computers(Computer** sfComputers, int sfCount);

	// Getter Methods.

	const char* Get_Name()const;
	const char* Get_Address()const;
	Computer** Get_Computers()const;
	const int Get_Count()const;

	// Methods. 

	CompStore& operator=(const CompStore& other);

	void AddComputer(const Computer* pc);

	void Print()const;
	void PrintComputersRamGreaterThan(short int RamSize);
	void PrintComputersYearBetween(size_t minYear, size_t maxYear);

	Computer* GetComputerById(size_t id);
	Computer** GetComputersByColor(const char* color);
	Computer** GetComputersSpaceBetween(size_t minSpace, size_t maxSpace);

	// Destructor.

	~CompStore();

};