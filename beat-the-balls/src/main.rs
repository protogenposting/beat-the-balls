use beat_the_balls::run;

fn main() {
    pollster::block_on(run());
}