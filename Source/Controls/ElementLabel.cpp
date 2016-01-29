#include "../../Include/Rocket/Controls/ElementLabel.h"
#include "../../Include/Rocket/Core/ElementDocument.h"

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
		if (this->HasAttribute("for"))
		{
			Core::Element* forElement = this->GetOwnerDocument()->GetElementById(this->GetAttribute<Core::String>("for", ""));
			if (forElement != NULL)
			{
				forElement->ProcessEvent(event);
			}
		}
		else
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
	}

	Element::ProcessEvent(event);
}

}
}