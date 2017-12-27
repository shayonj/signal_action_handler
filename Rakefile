require "bundler/gem_tasks"
require "rspec/core/rake_task"
require "rake/extensiontask"

RSpec::Core::RakeTask.new(:spec)
task default: :spec

spec = Gem::Specification.load('signal_action_handler.gemspec')
Rake::ExtensionTask.new('signal_action_handler', spec) do |ext|
  ext.lib_dir = "lib/signal_action_handler"
end

task install: :compile
