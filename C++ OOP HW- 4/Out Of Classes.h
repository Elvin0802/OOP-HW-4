#pragma once

// Static Variables. ---------------------------------------------------------------------------

size_t Computer::_staticID = 0;

// Constructors. -------------------------------------------------------------------------------

Computer::Computer()
{
	_staticID++;
	_ID = _staticID;

	_Model = nullptr;
	_Color = nullptr;
	_Year = 0;
	_CPU = nullptr;
	_RAM = 0;
	_Space = 0;
}
Computer::Computer(const char* Model) : Computer()
{
	Set_Model(Model);
}
Computer::Computer(const char* Model, const char* Color)
	: Computer(Model)
{
	Set_Color(Color);
}
Computer::Computer(const char* Model, const char* Color, const size_t Year)
	: Computer(Model, Color)
{
	Set_Year(Year);
}
Computer::Computer(const char* Model, const char* Color, const size_t Year, const char* CPU)
	: Computer(Model, Color, Year)
{
	Set_Cpu(CPU);
}
Computer::Computer(const char* Model, const char* Color, const size_t Year, const char* CPU, const short int RAM)
	: Computer(Model, Color, Year, CPU)
{
	Set_Ram(RAM);
}
Computer::Computer(const char* Model, const char* Color, const size_t Year, const char* CPU, const short int RAM, const size_t Space)
	: Computer(Model, Color, Year, CPU, RAM)
{
	Set_Space(Space);
}
Computer::Computer(const Computer& comp)
{
	_staticID++;

	this->_ID = comp._ID;

	this->Set_Model(comp._Model);
	this->Set_Color(comp._Color);
	this->Set_Year(comp._Year);
	this->Set_Cpu(comp._CPU);
	this->Set_Ram(comp._RAM);
	this->Set_Space(comp._Space);
}
Computer::Computer(Computer&& other)
{
	_staticID++;

	this->_ID = other._ID;
	other._ID = 0;

	this->_Model = other._Model;
	other._Model = nullptr;

	this->_Color = other._Color;
	other._Color = nullptr;

	this->_Year = other._Year;
	other._Year = 0;

	this->_CPU = other._CPU;
	other._CPU = nullptr;

	this->_RAM = other._RAM;
	other._RAM = 0;

	this->_Space = other._Space;
	other._Space = 0;
}

// Setter Methods. ---------------------------------------------------------------------------

void Computer::Set_Id(const int sfId)
{
	if (sfId > _staticID)
		_ID = sfId;
}
void Computer::Set_Model(const char* sfModel)
{
	if (sfModel == nullptr) assert(!"Gonderilen Model nullptr -dir.");

	int mLen = strlen(sfModel);

	if (mLen < 4) assert(!"Modelin Herf Sayi 3 den Chox Olmalidir.");

	if (_Model != nullptr) delete[] _Model;

	_Model = new char[mLen + 1];

	strcpy_s(_Model, mLen + 1, sfModel);
}
void Computer::Set_Color(const char* sfColor)
{
	if (sfColor == nullptr) assert(!"Gonderilen Reng nullptr -dir.");

	int cLen = strlen(sfColor);

	if (cLen < 2) assert(!"Rengin Herf Sayi 1 den Chox Olmalidir.");

	if (_Color != nullptr) delete[] _Color;

	_Color = new char[cLen + 1];

	strcpy_s(_Color, cLen + 1, sfColor);
}
void Computer::Set_Year(const size_t sfYear)
{
	if (!(sfYear > 2017 && sfYear < 2024)) assert(!"Computer Il-i 2018 ile 2023 (Daxildir) arasinda olmalidir.");

	_Year = sfYear;
}
void Computer::Set_Cpu(const char* sfCpu)
{
	if (sfCpu == nullptr) assert(!"Gonderilen CPU nullptr -dir.");

	int cpuLen = strlen(sfCpu);

	if (cpuLen <= 6) assert(!"CPU-nun Herf Sayi 6 -den Chox Olmalidir.");

	if (_CPU != nullptr) delete[] _CPU;

	_CPU = new char[cpuLen + 1];

	strcpy_s(_CPU, cpuLen + 1, sfCpu);
}
void Computer::Set_Ram(const short int sfRam)
{
	if (sfRam > 0 && sfRam < 512) {
		_RAM = sfRam;
		return;
	}
	assert(!"Ram 1 ile 512 Arasinda Olmalidir.");
}
void Computer::Set_Space(const size_t sfSpace)
{
	if (sfSpace > 0 && sfSpace < 2048) {
		_Space = sfSpace;
		return;
	}
	assert(!"Yaddash Sahesi 1 ile 2048 Arasinda Olmalidir.");
}


// Getter Methods. ---------------------------------------------------------------------------

const size_t Computer::Get_StaticId() const { return _staticID; }
const size_t Computer::Get_Id() const { return _ID; }
const char* Computer::Get_Model() const { return _Model; }
const char* Computer::Get_Color() const { return _Color; }
const size_t Computer::Get_Year() const { return _Year; }
const char* Computer::Get_Cpu() const { return _CPU; }
const short int Computer::Get_Ram() const { return _RAM; }
const size_t Computer::Get_Space() const { return _Space; }


// Methods. -----------------------------------------------------------------------------------

Computer& Computer::operator=(const Computer& other)
{
	if (_Model != nullptr)
	{
		delete[] _Model;
		_Model = nullptr;
	}
	if (_Color != nullptr)
	{
		delete[] _Color;
		_Color = nullptr;
	}
	if (_CPU != nullptr)
	{
		delete[] _CPU;
		_CPU = nullptr;
	}

	this->_ID = other._ID;

	this->Set_Model(other._Model);
	this->Set_Color(other._Color);
	this->Set_Year(other._Year);
	this->Set_Cpu(other._CPU);
	this->Set_Ram(other._RAM);
	this->Set_Space(other._Space);

	return *this;
}

void Computer::Print() const
{
	if (this == nullptr) return;

	cout << endl << "\tComputer ID : " << _ID << endl;
	cout << "\tComputer Model : " << (_Model == nullptr ? "Nullptr" : _Model) << endl;
	cout << "\tComputer Color : " << (_Color == nullptr ? "Nullptr" : _Color) << endl;
	cout << "\tComputer Year : " << _Year << endl;
	cout << "\tComputer CPU : " << (_CPU == nullptr ? "Nullptr" : _CPU) << endl;
	cout << "\tComputer RAM : " << _RAM << endl;
	cout << "\tComputer Space : " << _Space << endl;

	cout << endl<< endl;
}

// Destructor. --------------------------------------------------------------------------------

Computer::~Computer()
{
	if (_Model != nullptr)
	{
		delete[] _Model;
		_Model = nullptr;
	}
	if (_Color != nullptr)
	{
		delete[] _Color;
		_Color = nullptr;
	}
	if (_CPU != nullptr)
	{
		delete[] _CPU;
		_CPU = nullptr;
	}
}



// ------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------



//>>>>>>>   CompStore class.	<<<<<<<<<<<<<<<<<<


// Constructors. -------------------------------------------------------------------------------

CompStore::CompStore()
{
	_Name = nullptr;
	_Address = nullptr;
	_Computers = nullptr;
	_Count = 0;
}
CompStore::CompStore(const char* Name) : CompStore()
{
	Set_Name(Name);
}
CompStore::CompStore(const char* Name, const char* Address)
	: CompStore(Name)
{
	Set_Address(Address);
}
CompStore::CompStore(const char* Name, const char* Address, Computer** Computers, size_t Count)
	: CompStore(Name, Address)
{
	Set_Computers(Computers, Count);
}
CompStore::CompStore(const CompStore& other)
{
	this->Set_Name(other._Name);
	this->Set_Address(other._Address);
	this->Set_Computers(other._Computers, other._Count);
	this->_Count = other._Count;
}
CompStore::CompStore(CompStore&& other)
{
	this->_Name = other._Name;
	other._Name = nullptr;

	this->_Address = other._Address;
	other._Address = nullptr;

	this->_Computers = other._Computers;
	other._Computers = nullptr;

	this->_Count = other._Count;
	other._Count = 0;
}

// Setter Methods. ---------------------------------------------------------------------------

void CompStore::Set_Name(const char* sfName)
{
	if (sfName == nullptr) assert(!"Gonderilen Ad nullptr -dir.");

	int nameLen = strlen(sfName);

	if (nameLen < 6) assert(!"Adin Herf Sayi 6 den Chox Olmalidir.");

	if (_Name != nullptr) delete[] _Name;

	_Name = new char[nameLen + 1];

	strcpy_s(_Name, nameLen + 1, sfName);
}
void CompStore::Set_Address(const char* sfAddress)
{
	if (sfAddress == nullptr) assert(!"\nGonderilen Address nullptr -dir.\n");

	int adrLen = strlen(sfAddress);

	if (adrLen < 4) assert(!"\nAddressin Herf Sayi 3 den Chox Olmalidir.\n");

	if (_Address != nullptr) delete[] _Address;

	_Address = new char[adrLen + 1];

	strcpy_s(_Address, adrLen + 1, sfAddress);
}
void CompStore::Set_Computers(Computer** sfComputers, int sfCount)
{
	if (sfComputers == nullptr) assert(!"\nGonderilen Komputerler nullptr -dir.\n");
	if (sfCount < 1) assert(!"\nGonderilen Say Minimum 1 Olmalidir.\n");

	for (int p = 0; p < sfCount; p++) AddComputer(sfComputers[p]);
}


// Getter Methods. ---------------------------------------------------------------------------

Computer** CompStore::Get_Computers()const
{
	if (_Count > 0)
	{
		Computer** CopyStore = new Computer * [_Count];

		for (int pc = 0; pc < _Count; pc++)
		{
			Computer* CopyPC = new Computer(*(_Computers[pc]));

			CopyStore[pc] = CopyPC;
		}

		return CopyStore;
	}

	return nullptr;
}

const char* CompStore::Get_Name()const { return _Name; }
const char* CompStore::Get_Address()const { return _Address; }
const int CompStore::Get_Count()const { return _Count; }

// Methods. -----------------------------------------------------------------------------------

CompStore& CompStore::operator=(const CompStore& other)
{
	if (_Name != nullptr) {
		delete[] _Name;
		_Name = nullptr;
	}

	if (_Address != nullptr) {
		delete[] _Address;
		_Address = nullptr;
	}

	if (_Computers != nullptr)
	{
		for (int r = 0; r < _Count; r++)
		{
			if (_Computers[r] != nullptr)
			{
				delete _Computers[r];
				_Computers[r] = nullptr;
			}
		}
		delete[] _Computers;
		_Computers = nullptr;
	}

	this->Set_Name(other._Name);
	this->Set_Address(other._Address);
	this->Set_Computers(other._Computers, other._Count);
	this->_Count = other._Count;

	return *this;
}

void CompStore::AddComputer(const Computer* computer)
{
	Computer** NewComps = new Computer * [_Count + 1];

	for (int pc = 0; pc < _Count; pc++)
		NewComps[pc] = _Computers[pc];

	Computer* newPC = new Computer(*computer);

	NewComps[_Count] = newPC;

	if (_Computers != nullptr) delete[] _Computers;

	_Computers = NewComps;
	_Count++;
}

void CompStore::Print()const
{
	if (this == nullptr) return;

	cout << endl << "\t\tCompStore Name : " << (_Name == nullptr ? "nullptr" : _Name) << endl;
	cout << "\t\tCompStore Address : " << (_Address == nullptr ? "nullptr" : _Address) << endl;
	cout << "\t\tComputer Count in Garage : " << _Count << endl;

	for (int pc = 0; pc < _Count; pc++)
	{
		cout << "<<---------------------->>\n";
		_Computers[pc]->Print();
	}
	cout << "\n<<<-------------------------------------->>>\n\n";
}
void CompStore::PrintComputersRamGreaterThan(short int RamSize)
{
	if (RamSize < 0) return;

	for (int p = 0; p < _Count; p++)
	{
		if (_Computers[p]->Get_Ram() >= RamSize)
			_Computers[p]->Print();
	}

}
void CompStore::PrintComputersYearBetween(size_t minYear, size_t maxYear)
{
	if (minYear < 2018 || maxYear > 2023) return;

	for (int p = 0; p < _Count; p++) 
	{
		if (_Computers[p]->Get_Year() >= minYear && _Computers[p]->Get_Year() <= maxYear)
			_Computers[p]->Print();
	}
}

Computer* CompStore::GetComputerById(size_t id)
{
	if (id < 1) assert(!"\nGonderilen id 0 -dan Boyuk Olmalidir !\n");

	for (int p = 0; p < _Count; p++)
	{
		if (_Computers[p]->Get_Id() == id)
		{
			Computer* PC = new Computer(*(_Computers[p]));

			return PC;
		}
	}

	return nullptr;
}
Computer** CompStore::GetComputersByColor(const char* color)
{
	if (color == nullptr) assert(!"\nGonderilen Reng nullptr -dir !\n");

	int countPCs = 0;

	for (int p = 0; p < _Count; p++)
		if (strcmp(_Computers[p]->Get_Color(), color) == 0)
			countPCs++;

	Computer** Comps;

	if (countPCs > 0)
		Comps = new Computer * [countPCs];
	else return nullptr;

	countPCs = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (strcmp(_Computers[ap]->Get_Color(), color) == 0)
			Comps[countPCs++] = new Computer(*(_Computers[ap]));

	return Comps;
}
Computer** CompStore::GetComputersSpaceBetween(size_t minSpace, size_t maxSpace)
{
	if (maxSpace < minSpace) return nullptr;

	int countPCs = 0;

	for (int p = 0; p < _Count; p++)
		if (_Computers[p]->Get_Space() >= minSpace && _Computers[p]->Get_Space() <= maxSpace)
			countPCs++;

	Computer** Comps;

	if (countPCs > 0)
		Comps = new Computer * [countPCs];
	else return nullptr;

	countPCs = 0;

	for (int p = 0; p < _Count; p++)
		if (_Computers[p]->Get_Space() >= minSpace && _Computers[p]->Get_Space() <= maxSpace)
			Comps[countPCs++] = new Computer(*(_Computers[p]));

	return Comps;

}

// Destructor. --------------------------------------------------------------------------------

CompStore::~CompStore()
{
	if (_Name != nullptr) {
		delete[] _Name;
		_Name = nullptr;
	}

	if (_Address != nullptr) {
		delete[] _Address;
		_Address = nullptr;
	}

	if (_Computers != nullptr)
	{
		for (int r = 0; r < _Count; r++)
		{
			if (_Computers[r] != nullptr)
			{
				delete _Computers[r];
				_Computers[r] = nullptr;
			}
		}
		delete[] _Computers;
		_Computers = nullptr;
	}
}