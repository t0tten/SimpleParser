.PHONY: all clean run
SOURCES=Main.cpp src/Pinetime.cpp src/WatchFace.cpp src/FileManagement.cpp src/parser/WatchFaceParser.cpp src/parser/exceptions/ArithmeticException.cpp src/parser/exceptions/ParserException.cpp src/parser/matchers/RegexMatcher.cpp src/parser/matchers/IfRegexMatcher.cpp src/parser/matchers/ForRegexMatcher.cpp src/parser/matchers/VariableRegexMatcher.cpp src/parser/types/UiRegex.cpp src/ui_components/UiComponent.cpp src/ui_components/built-in_functions/LineUiComponent.cpp src/ui_components/built-in_functions/CircleUiComponent.cpp src/ui_components/built-in_functions/TextUiComponent.cpp src/ui_components/built-in_functions/RectangleUiComponent.cpp src/ui_components/built-in_functions/ColorUiComponent.cpp src/ui_components/built-in_variables/VariableUiComponent.cpp src/ui_components/built-in_variables/ClockVariableUiComponent.cpp src/ui_components/built-in_variables/StringVariableUiComponent.cpp src/ui_components/built-in_variables/BooleanVariableUiComponent.cpp src/ui_components/built-in_variables/BatteryVariableUiComponent.cpp src/ui_components/built-in_variables/BluetoothVariableUiComponent.cpp src/ui_components/built-in_variables/DateVariableUiComponent.cpp src/ui_components/built-in_variables/HeartVariableUiComponent.cpp src/ui_components/built-in_variables/StepsVariableUiComponent.cpp src/ui_components/arithmetics/ArithmeticUiComponent.cpp src/ui_components/arithmetics/IfUiComponent.cpp src/ui_components/arithmetics/ForUiComponent.cpp
OBJECTS=$(SOURCES:.cpp=.o)
BINARY=bin/Pinetime

all: $(BINARY)

clean:
	$(RM) $(BINARY) $(OBJECTS)

$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@