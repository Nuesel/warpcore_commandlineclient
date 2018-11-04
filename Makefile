.PHONY: clean All

All:
	@echo "----------Building project:[ client - Debug ]----------"
	@"$(MAKE)" -f  "client.mk"
clean:
	@echo "----------Cleaning project:[ client - Debug ]----------"
	@"$(MAKE)" -f  "client.mk" clean
