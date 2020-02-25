#pragma once
/*
	- Tutucu olarak kullanýlacak taban sýnýf
	- Nesnelerine otomatik benzersiz ve deðiþmez 
	  kimlendirme yapar

	- Kalýtým ile türetilerek Fonksiyon tutucu, 
	  nesne tutucu gibi herhangi bir sýnýfta 
	  kullanýlabilir. Yine benzersiz ve deðiþmez 
	  kimlendirmeyi otomatik yapar
	
*/
class Handle {
	static size_t identifer;
public:
	virtual ~Handle();
	const size_t id;
	Handle();
};

