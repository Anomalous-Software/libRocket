#include "../../Include/Rocket/Controls/ElementLabel.h"

namespace Rocket {
namespace Controls {

ElementLabel::ElementLabel(const Rocket::Core::String& tag) : Core::Element(tag)
{

}

ElementLabel::~ElementLabel()
{
}

void ElementLabel::ProcessEvent(Core::Event& event)
{
	// Detect click events
	if (event.GetTargetElement() == this &&	(event == "click"))
	{
		//Note that we have to loop since the ElementFormControlInput class does not pass its OnChildAdded to the superclass.
		//We don't want to modify things too much, so we will just loop when clicked searching for the child input, not really
		//a big deal.
		int childCount = this->GetNumChildren();
		Core::Element* child;
		for (int i = 0; i < childCount; ++i)
		{
			child = this->GetChild(i);
			if (child->GetTagName() == "input")
			{
				child->ProcessEvent(event);
				i = childCount; //break loop
			}
		}
	}

	Element::ProcessEvent(event);
}

}
}