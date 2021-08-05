all: clean generate_proto

generate_proto:
	@python3 -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. arm.proto
	@python3 -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. comp.proto

clean:
	@$(RM) -rf *.pyc *pb2*.py __pycache__/

run_serv_arm: generate_proto
	@python3 serv_arm.py $(arg)

run_cli_arm: generate_proto
	@python3 cli_arm.py $(arg)

run_serv_comp: generate_proto
	@python3 serv_comp.py $(arg1) $(arg2) $(arg3)

run_cli_comp: generate_proto
	@python3 cli_comp.py $(arg)