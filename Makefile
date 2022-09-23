.PHONY: clean All

All:
	@echo "----------Building project:[ TicTacToe - Debug ]----------"
	@cd "TicTacToe" && "$(MAKE)" -f  "TicTacToe.mk"
clean:
	@echo "----------Cleaning project:[ TicTacToe - Debug ]----------"
	@cd "TicTacToe" && "$(MAKE)" -f  "TicTacToe.mk" clean
