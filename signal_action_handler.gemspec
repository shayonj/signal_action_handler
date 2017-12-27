# coding: utf-8
lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "signal_action_handler/version"

s = Gem::Specification.new do |spec|
  spec.name          = "signal_action_handler"
  spec.version       = SignalActionHandler::VERSION
  spec.platform      = Gem::Platform::RUBY

  spec.authors       = ["Shayon Mukherjee"]
  spec.email         = ["dev@shayon.me"]

  spec.summary       = "List the current action handlers for all Signals."
  spec.description   = "List current action handlers for all Signals, without having to override the current action handlers to retrieve the same information."
  spec.homepage      = "https://github.com/shayonj/signal_action_handler"
  spec.license       = "MIT"

  spec.required_ruby_version  = ">= 2.0.0"

  spec.extensions     << "ext/signal_action_handler/extconf.rb"

  spec.files          = Dir.glob("ext/**/*.{c,rb}") + Dir.glob("lib/**/*.rb")

  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.15"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"

  spec.add_development_dependency "rake-compiler", "~> 1.0.4"
end
