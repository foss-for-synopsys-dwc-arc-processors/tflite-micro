ifeq ($(TARGET_ARCH), arc)
ifneq ($(filter $(ARC_TAGS), mli20_experimental), )

# Patch of arc make project to adjust it specifically for micro speech example. 
# In particular:
# - Adapt the model to be used with MLI by transposing weights tensors

  MICRO_SPEECH_HDRS += \
  micro_speech_patch.txt
  
  MICRO_SPEECH_TEST_HDRS += \
  micro_speech_patch.txt
  
  MICRO_SPEECH_MOCK_HDRS += \
  micro_speech_patch.txt

MODEL_PATH = $(GENERATED_SRCS_DIR)tensorflow/lite/micro/examples/micro_speech/

# Apply changes in generated project files. 
# See related comment echoed (@echo <comment>) after each change 
# to get understanding on it's purpose.
%/micro_speech_patch.txt: $(MODEL_PATH)/micro_speech_model_data.cc

	@python tensorflow/lite/micro/tools/make/targets/arc/adaptation_tool.py $<
	@echo Makefile: Adapted the model to be used with MLI >> $@

endif
endif
