
#include "Editor.h"

#include "./commands/CopyCommand.h"
#include "./commands/PasteCommand.h"
#include "./commands/SaveCommand.h"

namespace dp {
	Editor::Editor() {
		InitButtons();
	}

	Editor::Editor(const std::string& content): _content(content) {
		InitButtons();
	}

	void Editor::OnRender() {
		std::cout << "Editor: \n";
		for (auto& button : _buttons) button.OnRender(true);

		std::cout << "\n" << _content << std::endl;
	}

	void Editor::OnUpdate() {
		int choice = -1;

		do {
			std::cout << "Enter your choice: ";
			std::cin >> choice;
		} while (choice < 0 || choice > _buttons.size());

		if (choice == _buttons.size()) {
		}
		_buttons[choice].OnClick();
	}

	void Editor::InitButtons() {
		Button       saveButton("Save");
		SaveCommand* saveCommand = new SaveCommand();
		saveButton.AddCommand(saveCommand);

		Button       copyButton("Copy");
		CopyCommand* copyCommand = new CopyCommand();
		copyButton.AddCommand(copyCommand);

		Button        pasteButton("Paste");
		PasteCommand* pasteCommand = new PasteCommand();
		pasteButton.AddCommand(pasteCommand);

		_buttons.push_back(saveButton);
		_buttons.push_back(copyButton);
		_buttons.push_back(pasteButton);
	}
} // namespace dp