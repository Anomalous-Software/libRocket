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
	bool fireToBaseClass = true;
	// Detect click events
	if (event.GetTargetElement() == this &&	(event == "click"))
	{
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

	if (fireToBaseClass)
	{
		Element::ProcessEvent(event);
	}
}

}
}