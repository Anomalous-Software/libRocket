#ifndef ROCKETCONTROLELEMENTLABEL_H
#define ROCKETCONTROLELEMENTLABEL_H

#include "../../Include/Rocket/Core/EventListener.h"
#include "../Core/Element.h"
#include "Header.h"

namespace Rocket {
namespace Controls {

class ROCKETCONTROLS_API ElementLabel : public Core::Element
{
public:
	/// Constructs a new ElementLabel. This should not be called directly; use the Factory
	/// instead.
	/// @param[in] tag The tag the element was declared as in RML.
	ElementLabel(const Rocket::Core::String& tag);
	virtual ~ElementLabel();

	// Called for every event sent to this element or one of its descendants.
	// @param[in] event The event to process.
	virtual void ProcessEvent(Rocket::Core::Event& event);
};

}
}

#endif