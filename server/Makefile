IMAGE_NAME ?= bionade-robot
IMAGE_TAG ?= latest

build:
	docker build -t "${IMAGE_NAME}:${IMAGE_TAG}" -f "./Dockerfile" .

.ONESHELL: build
.PHONY: build