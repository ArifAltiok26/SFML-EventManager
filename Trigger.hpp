#pragma once

/*
	Tutucularý (Handle nesnelerini) bir arada tutmak amacýyla
	ekleme, silme ve gerektiðinde tetikleme iþlemleri arayüzüdür

*/
class Handle;
class Trigger {
public:
	
	virtual size_t add(Handle* handle) = 0;
	//Tutucu ekleme geri dönüþ deðeri tutucunun benzersiz kimliðidir

	virtual bool remove(size_t id) = 0;
	// parametresi tutucunun kimliði olacak þekilde silindiyse true
	// silinemedi veya bulunamadi false döndürmesi amaçlanýr
	
	virtual void triggered()const = 0;
	//Nesne içindeki tüm tutucularý ayný anda tetikler
};

