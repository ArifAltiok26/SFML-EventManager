#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
/*
	- Event Sýnýflarý

	- Herbir sýnýf Event sýnýfýndan türer. 
	  Fakat Event sýnýfý kendi baþýna oluþturulamaz.
	
	- Eventler Donaným ve Yazýlým olarak iki kategoriye ayrýlmýþtýr.
	
	- Her bir event, gerçekleþmesi durumunda çalýþacak 
	  fonksiyon için almasý gereken parametreyi Args olarak belirtir.
	
	- Retval deðeri fonksiyonun geri dönüþ deðerini belirtir.
	  Bu event sýnýfý için void olarak belirtilmiþtir. Ayrýca belirtmek gerekmez.
	
	- Donanýmsal eventlerin parametreleri içi boþtur. Deðer içermez.
	
	- Kendi alt Event sýnýfýnýzý oluþturmak isterseniz
	  Event sýnýfýndan kalýtým alýp, kurucusunda tipini parametre
	  olarak gönderin. Ayrýca bu eventin gerçekleþmesi durumunda
	  tetiklenecek fonksiyonun parametresini Args þeklinde belirtin. 

	- EventTraits sýnýfý Eventin Args,Retval,FunctionType,Function
	  þeklindeki özelliklerini tespit eder.
	  Function tetiklenecek fonksiyonu,
	  FunctionType fonksiyonun geri dönüþ ve parametrelerini birliðini,
	  Retval fonksiyonun geri dönüþ tipini,
	  Args fonksiyonun parametre tipini belirtir.


*/
class EventManager;
class Event{
protected:
	sf::Event::EventType type;
	Event(sf::Event::EventType);
	friend class EventManager;
public:
	using Retval = void;
};

struct Void {};

class HardwareEvent : public Event {
protected:
	using Event::Event;
public:
	using Args = Void;
};

class SoftwareEvent : public Event {
protected:
	using Event::Event;
};

struct ClosedEvent : HardwareEvent {
	ClosedEvent();
};

struct LostFocusEvent : HardwareEvent {
	LostFocusEvent();
};

struct GainedFocusEvent : HardwareEvent {
	GainedFocusEvent();
};

struct SizeEvent : SoftwareEvent {
	SizeEvent();
	using Args = sf::Event::SizeEvent;
};


struct MouseMoveEvent : SoftwareEvent {
	MouseMoveEvent();
	using Args = sf::Event::MouseMoveEvent;
};

struct MousePressedEvent : SoftwareEvent {
	MousePressedEvent();
	using Args = sf::Event::MouseButtonEvent;
};


struct MouseReleasedEvent : SoftwareEvent {
	MouseReleasedEvent();
	using Args = sf::Event::MouseButtonEvent;
};


struct KeyPressedEvent : SoftwareEvent {
	KeyPressedEvent();
	using Args = sf::Event::KeyEvent;
};

struct KeyReleasedEvent : SoftwareEvent {
	KeyReleasedEvent();
	using Args = sf::Event::KeyEvent;
};



// bu sýnýfý degistirmeyin args ve handle tespiti yapar
template<typename Event>
struct EventTraits {
	using Args = typename Event::Args;
	using Retval = void;
	using FunctionType = typename Retval(Args);
	using Function = typename std::function<FunctionType>;
};
