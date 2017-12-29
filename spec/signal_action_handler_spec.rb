require "spec_helper"

RSpec.describe SignalActionHandler do
  it "has a version number" do
    expect(SignalActionHandler::VERSION).not_to be nil
  end

  context ".info" do
    it "return value is type hash" do
      expect(SignalActionHandler.info.class).to eq(Hash)
    end

    it "reports accurate current signal being set as the current handler" do
      signal = "TERM"
      old_handler = Signal.trap(signal, "IGNORE")
      current_handler = SignalActionHandler.info[signal]

      expect(old_handler).to_not eq(current_handler)
      expect(current_handler).to eq("IGNORE")
    end

    it "has the same signals as the default Signals.list" do
      expect(SignalActionHandler.info.keys).to eq(Signal.list.keys - SignalActionHandler::RESERVED_SIGNALS)
    end
  end
end
