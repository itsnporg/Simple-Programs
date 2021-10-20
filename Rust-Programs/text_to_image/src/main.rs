extern crate image;
extern crate imageproc;
extern crate rusttype;

use text_io::read;

fn main() {
    let white = image::Rgb([255u8, 255u8, 255u8]);
    println!("Send the word to convert to image to: ");

    let word:String = read!("{}\n");
    let len_of_word = word.chars().count() as f32;

    let font_data: &[u8] = include_bytes!("./fonts/OpenSans-Regular.ttf");
    let font = rusttype::Font::try_from_bytes(font_data);

    match font{
        Some(t) => {
            let mut scramble_image = image::ImageBuffer::new((len_of_word * 17.55) as u32, 57);

            for (_x, _y, pixel) in scramble_image.enumerate_pixels_mut(){
                *pixel = image::Rgb([54u8, 57u8, 63u8])
            }

            imageproc::drawing::draw_text_mut(&mut scramble_image, white, 5, 5, rusttype::Scale::uniform(45.0), &(t), &word);
            scramble_image.save("text_to_image.png").unwrap();
        },
        _ => println!("Font go brrr")
    }
}